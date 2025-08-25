`timescale 1ns/1ps
module _Data_Sampler_TB();

	reg clk;
	reg clk16;
	reg clk100khz;
	//reg clk2;
	reg rst;
	reg Data;
	
	wire [7:0] sampler;		//lembrar que sampler tem 8 bits por se tratar dos 8 bits mais significativos, mas a palavra deve dter 10
	wire CS;
	//wire [3:0] countSamp;
	
	//wire [7:0] countCtrl;
	wire StartConv;
	
	wire BASK;
	
	//wire start;
	//reg [7:0] DutyCycle;
	//reg [9:0] cnt;
	//reg clk16;
	//reg clk100;
	//reg start;
	reg [7:0] tmp2;

	_Data_Sampler _Data_Sampler_DUT
		(
			.clk(clk),
			.rst(rst),
			.Data(Data),
			.sampler(sampler),
			.CS(CS),
			//.countSamp(countSamp),
			//.countCtrl(countCtrl),
			.StartConv(StartConv)
		);
		
	
		
	_BASK_PWM _BASK_PWM_DUT
		(
			.clk1_6khz(clk16),
			.clk100khz(clk100khz),
			.rst(rst),
			.sampler(sampler),
			.BASK(BASK),
			//.start(start),		
			.Allow(StartConv)
			//.DutyCycle(DutyCycle)
		);
	
	
	initial	
		begin
			//$init_signal_spy("/_BASK_PWM_DUT/DutyCycle", "/_Data_Sampler_TB/DutyCycle", 1);
			//$init_signal_spy("/_BASK_PWM_DUT/cnt", "/_Data_Sampler_TB/cnt", 1);
			//$init_signal_spy("/_BASK_PWM_DUT/clk16", "/_Data_Sampler_TB/clk16", 1);
			$init_signal_spy("/_BASK_PWM_DUT/tmp2", "/_Data_Sampler_TB/tmp2", 1);
			
			//reset
			rst = 1;
			clk = 0;
			clk16 = 0; 
			clk100khz = 0;
			//clk2 = 0;
			#1 rst = 0;
			#1 rst = 1;
			
			Data = 1;
			
			/*
			//a conversao começa em
			#4940;
			Data = 0;
			#20;
			Data = 0; //bit 7
			#20;
			Data = 1; //bit 6
			#20;
			Data = 1; //bit 5
			#20;
			Data = 1; //bit 4
			#20;
			Data = 0; //bit 3
			#20;
			Data = 0; //bit 2
			#20;
			Data = 1; //bit 1
			#20;
			Data = 0; //bit 0
			#20; // end
			Data = 1;
			*/
			
			#40000000;
			$finish;
			
			//11001000 o que se espera ver no registro no fianal
		end
	
	
	always #15.5215195 Data = ~Data;
	
	//50KHz
	always #10000 clk = ~clk;
	
	//50MHz
	//always #10 clk2 = ~clk2;

	always #312500 clk16 = ~clk16;
	always #100 clk100khz = ~clk100khz;
	


endmodule 