module _4ASK_PWM
(
	input clk, 					//clk de 50mhz
	input clk800hz,
	input rst,
	input [7:0] sampler,		//vem direto do shift register do sata sampler
	input Allow,				//sinal de frequencia de 200hz
	input clk100khz,
	
	output reg out_3_3,
	output reg out_2_7,
	output reg out_2_1,
	output reg out_1_5
);

	reg [7:0] tmp;		//registro de atualizacao e leitura
	reg [7:0] tmp2;
	
	reg [3:0] ctrl;
	

	
	reg T;				//registro de sincronismo 
	
		
	//gerando as saidas
	always @(posedge clk or negedge rst)
		begin
			if (~rst) 
				begin
					out_3_3 <= 0;
					out_2_7 <= 0;
					out_2_1 <= 0;
					out_1_5 <= 0;
				end
			else
				begin
						out_3_3 <= 1'bz;
						out_2_7 <= 1'bz;
						out_2_1 <= 1'bz;
						out_1_5 <= 1'bz;
						
					case(tmp2[7:6])
						2'b00: out_1_5 <= clk100khz;
						2'b01: out_2_1 <= clk100khz;
						2'b10: out_2_7 <= clk100khz;
						2'b11: out_3_3 <= clk100khz;
					endcase
				end
		end

			
	
	//Allow é um sinal que majoritariamente fica em nivel alto, ativa em baixo
	//atualiza o registro de leiura com o valor da nova conversao
	always@(posedge Allow or negedge rst)
		begin
			if(~rst) 
				begin
					tmp <= 0;
					T <= 0;
				end
			else 
				begin
					tmp <= sampler;
					T <= 1;
				end
		end
		
		
	//desloca o registro 8 vezes, depois atualiza o valor e repete
	always@(posedge clk800hz or negedge rst)
		begin
			if(~rst) ctrl <= 0;
			else if(T)
						begin
							if(ctrl <= 6) 
								begin
									tmp2 <= tmp2 << 2;
									ctrl <= ctrl + 1;
								end
								else 
									begin
										tmp2 <= tmp;
										ctrl <= 0;
									end
						end
		end
		
	
endmodule 