`timescale 10ns/10ps
module BitsRxNPWM_TB();

	reg clk16;
	reg clk204khz;
	reg clktst;
	reg rst;
	reg data;
	
	reg [9:0] DutyCycle;
	reg [9:0] PWM;
	reg [3:0] intcnt;
	reg [9:0] temp;
	
	wire out;
	
	
	BitsRxNPWM BitsRxNPWM_DUT
		(
			.clk16(clk16),
			.clk204khz(clk204khz),
			.rst(rst),
			.data(data),
			.out(out)
		);
	
	initial	
		begin
			$init_signal_spy("/BitsRxNPWM_DUT/DutyCycle", "/BitsRxNPWM_TB/DutyCycle", 1);		
			$init_signal_spy("/BitsRxNPWM_DUT/PWM", "/BitsRxNPWM_TB/PWM", 1);	
			$init_signal_spy("/BitsRxNPWM_DUT/intcnt", "/BitsRxNPWM_TB/intcnt", 1);			
			$init_signal_spy("/BitsRxNPWM_DUT/temp", "/BitsRxNPWM_TB/temp", 1);			

			clk16 = 0;
			clk204khz = 0;
			data = 8'b00001111;
			rst = 1;
			clktst = 0;
			
			#2 rst = 0;
			#2 rst = 1;
			
			#20000000;
			$finish;
		end
		

		always #31250 clk16 = ~clk16;
		always #245 clk204khz = ~clk204khz;
		always #2.1564165162 clktst = ~clktst;
			
		
		always@(posedge clktst)
			begin
				data <= data + 5;
			end

endmodule 