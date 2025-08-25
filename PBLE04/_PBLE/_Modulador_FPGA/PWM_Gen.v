module PWM_Gen
(
	input clk,
	input rst,
	input [14:0] DutyCycle,
	
	output reg PWM_Pin
);

	reg [14:0] cnt_cos_01;
	reg [14:0] cnt_cos_02;
		
		
	//	gera o sinal via PWM, 2000 amostras por segundo
	always @(posedge clk or negedge rst)
	begin
		if (!rst)
			begin
				cnt_cos_01 <= 0;
				PWM_Pin <= 0;
			end
			else
				begin
					if(cnt_cos_01 < DutyCycle) PWM_Pin <= 1;
					else PWM_Pin <= 0;

					cnt_cos_01 <= cnt_cos_01 + 1;

					if(cnt_cos_01 >= 24999) cnt_cos_01 <= 0;
				end
	end

	

endmodule
