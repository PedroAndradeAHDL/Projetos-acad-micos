module _Data_Sampler
(
	input clk,	//deve ser alimentado com 50khz
	input rst,
	input Data,
	
	output reg CS,
	output reg StartConv,		//flag de controle de conversao
	output reg [7:0] sampler 	//registro de dados 
);

	reg [7:0] countCtrl;	//contador de controle de frequencia de taxa de amostragem = 200Hz
	
	
	//always de controle: contador 
	always@(posedge clk or negedge rst)
		begin
			if(~rst)
				begin
					countCtrl <= 0;
					StartConv <= 1;	//reset em nivel alto
				end else
						begin							
							//se bate o tempo do periodo de 5ms, reseta o contador e habilita a conversao
							if(countCtrl == 249)
								begin
									countCtrl <= 0;
									StartConv <= 0;
								end else	
										begin
											//quando a conversoa terminar, desabilita a conversao 
											if(countCtrl == 13) 
												begin
													StartConv <= 1;
													countCtrl <= countCtrl + 1;
												end
											//incrementa
											else	countCtrl <= countCtrl + 1;
										end
						end
		end
		
		
	//o mcp atualiza na borda de descida 
	always@(posedge clk or negedge rst)
		begin
			if(~rst)
				begin
					CS <= 1;			//coloca CS em nivel alto=desabilita conversor
					sampler <= 0;	//zera o registro de controle
				end else
						begin
							if(~StartConv)
							begin
								CS <= 0;
								sampler <= (sampler << 1) | Data;
							end
								else
									begin
										CS <= 1;
										//depois disso, sampler contera o valor dos 8 bits mais significativos do 
										//MCP3002 referente ao sinal convertido
									end
						end
		end

endmodule 