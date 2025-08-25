module _Modulador_FPGA
(
	input clk,
	input DataMCP3002,		//pino de saida do MCP3002
	input DataBASKDem,			//pino da demodulacao do bask
	
	output wire PWM_Pin,
	output wire BASK_Pin,
	output wire CLK_50k,
	output wire CS,
	output wire FinalRX,		//saida do bask modulado em PWM, saida final do projeto
	
	output wire out_3_3,
	output wire out_2_7,
	output wire out_2_1,
	output wire out_1_5
);
	
	wire [14:0] DutyCycle;
	wire rst;
	wire StartConv;
	wire clk1_6khz;
	wire clk160khz;
	wire clk100khz;
	wire clk204khz;
	wire clk800hz;
	
	wire [7:0] shRegisterOut;
	
	_First_Clock_Reset
		(
			.Clk(clk),
			.rst(rst)
		);

	LUT_Access LUT_Access_DUT
		(
			.clk(clk),
			.rst(rst),
			
			.out(DutyCycle)
		);
		
		
	PWM_Gen PWM_Gen_DUT
		(
			.clk(clk),
			.rst(rst),
			.DutyCycle(DutyCycle),
			
			.PWM_Pin(PWM_Pin)
		);
		
		
	_Data_Sampler _Data_Sampler_DUT
		(
			.clk(CLK_50k),
			.rst(rst),
			.Data(DataMCP3002),
			.CS(CS),
			.StartConv(StartConv),
			.sampler(shRegisterOut)
		);
		
	_BASK_PWM _BASK_PWM_DUT
		(
			.clk1_6khz(clk1_6khz),
			.clk100khz(clk100khz),
			.rst(rst),
			.sampler(shRegisterOut),
			.Allow(StartConv),
			.BASK(BASK_Pin)
		);
		
	_4ASK_PWM _4ASK_PWM_DUT
		(
			.clk(clk),
			.clk800hz(clk800hz),
			.clk100khz(clk100khz),
			.rst(rst),
			.sampler(shRegisterOut),
			.Allow(StartConv),
			.out_3_3(out_3_3),
			.out_2_7(out_2_7),
			.out_2_1(out_2_1),
			.out_1_5(out_1_5)
		);
		
	PLL PLL_DUT
		(
			.clk(clk),
			.rst(rst),
			.clk50khz(CLK_50k),
			.clk1_6khz(clk1_6khz),
			.clk100khz(clk100khz),
			.clk160khz(clk160khz),
			.clk204khz(clk204khz),
			.clk800hz(clk800hz)
		);
		
	BitsRxNPWM BitsRxNPWM_DUT
		(
			.clk16(clk1_6khz),
			.clk204khz(clk204khz),
			.rst(rst),
			.data(DataBASKDem),
			.out(FinalRX)
		);
		

endmodule 