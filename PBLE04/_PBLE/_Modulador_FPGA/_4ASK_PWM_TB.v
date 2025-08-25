`timescale 10ns/10ps
module _4ASK_PWM_TB();

	reg clk50mhz;
	reg clk800hz;
	reg rst;
	reg [7:0] sampler;
	reg Allow;
	
	reg [7:0] tmp2;
	reg [7:0] tmp;
	reg [3:0] ctrl;
	
	wire _4ASK;
	
	_4ASK_PWM _4ASK_PWM_DUT
		(
			.clk(clk50mhz),
			.clk800hz(clk800hz),
			.rst(rst),
			.sampler(sampler),
			.Allow(Allow),
			._4ASK(_4ASK)
		);
		
		
		initial
			begin
				$init_signal_spy("/_4ASK_PWM_DUT/tmp2", "/_4ASK_PWM_TB/tmp2", 1);
				$init_signal_spy("/_4ASK_PWM_DUT/tmp", "/_4ASK_PWM_TB/tmp", 1);
				$init_signal_spy("/_4ASK_PWM_DUT/ctrl", "/_4ASK_PWM_TB/ctrl", 1);

				
				clk50mhz = 0;
				clk800hz = 0;
				rst = 1;
				sampler = 8'b11100100;
				Allow = 1;
				#2 Allow = 0;
				#2 Allow = 1;
				
				#5 rst = 0;
				#5 rst  =1;
				
				#8000000 $finish;
			end

			//clk de 50mhz
			always #1 clk50mhz = ~clk50mhz;
			always #62499 clk800hz = ~clk800hz;

			
			initial 
				begin
					 forever 
						 begin
							  Allow = 1;
							  #500000;
							  Allow = 0;
							  #16000;
						 end
				end

				
			/*	
			always@(posedge Allow)
				begin
					sampler <= sampler + 5;
				end*/
endmodule 