module BitsRxNPWM
(
	input clk16,
	input clk204khz,
	input rst,
	input data,
	
	output reg out
);

	reg [9:0] temp;
	(*keep*) reg [9:0] DutyCycle;
	(*keep*) reg [9:0] PWM;
	reg [3:0] intcnt;
	reg Allow;
	
	
	//coleta de bits
	always @(posedge clk16 or negedge rst) 
		begin
			 if (~rst) 
				begin
					temp <= 0;
					intcnt <= 0;
					DutyCycle <= 0;
					Allow <= 0;
				end else 
						begin
							temp[9:2] <= {temp[8:2], data};  // coleta de 8 bits
							intcnt <= intcnt + 1;
							
							if(intcnt == 7)
								begin
									DutyCycle <= {temp[8:2], data, 2'b00}; // zera bits menos significativos
									intcnt <= 0;
									Allow <= 1;
								end
					end
		end
		
		
	//gera o PWM com 200 amostras por segundo
	always@(posedge clk204khz or negedge rst)
		begin
			if(~rst) 
				begin
					PWM <= 0;
					out <= 0;
				end
				else if(Allow)
							begin
								if(PWM <= DutyCycle) out <= 1;
									else out <= 0;
									
								PWM <= PWM + 1;
									
								if(PWM >= 1019) PWM <= 0;
							end
		end


endmodule 
