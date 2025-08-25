module _BASK_PWM
(
	input clk100khz,
	input clk1_6khz,
	input rst,
	input [7:0] sampler,		//vem direto do shift register do sata sampler
	input Allow,				//sinal de frequencia de 200hz
	
	output wire BASK
);

	reg [7:0] tmp;		//registro de atualizacao e leitura
	reg [7:0] tmp2;
	reg [3:0] ctrl;
	reg T;
	
		
	//cada bit fica na saida por 5ms (200hz)
	and bask_out(BASK, clk100khz, tmp2[7]);
			
	
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
	always@(posedge clk1_6khz or negedge rst)
		begin
			if(~rst) ctrl <= 0;
			else if(T)
						begin
							if(ctrl <= 6) 
								begin
									tmp2 <= tmp2 << 1;
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