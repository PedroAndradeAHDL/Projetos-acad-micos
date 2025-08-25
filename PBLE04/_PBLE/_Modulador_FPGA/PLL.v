module PLL
(
	input clk,	//clk de 50Mhz
	input rst,
	
	output reg clk50khz,
	output reg clk1_6khz,
	output reg clk100khz,
	output reg clk160khz,
	output reg clk204khz,
	output reg clk800hz
);

	reg [9:0] cnt;
	reg [13:0] clk16Gen;		//contador pra gerar o clock de 1600hz
	reg [7:0] clk100Gen;		//contador pra gerar o clock de 100khz
	reg [3:0] clk160khzGen;
	reg [6:0] clk204khzGen;
	reg [14:0] clk800hzGen;

	//gera o clock de 50khz
	always@(posedge clk or negedge rst)
		begin
			if(~rst) 
				begin
					cnt <= 0;
					clk50khz <= 0;
				end
			else	
				begin
					if(cnt == 499)
						begin
							clk50khz <= ~clk50khz;
							cnt <= 0;
						end else cnt <= cnt + 1;
				end
		end
		
		
		
	//gera o clock de 1.6khz
	always@(posedge clk or negedge rst)
		begin
			if(~rst)
				begin
					clk16Gen <= 0;
					clk1_6khz <= 0;
				end
			else if(clk16Gen == 15624) 
					begin
						clk1_6khz <= ~clk1_6khz;
						clk16Gen <= 0;
					end
					else clk16Gen <= clk16Gen + 1; 
		end
		
		
		
	//gera o clock de 100khz
	//estoum diminuindo para testar no alice, lembrar de trocar pra 249 e registro pra 7:0
	always@(posedge clk or negedge rst)
		begin
			if(~rst)
				begin
					clk100Gen <= 0;
					clk100khz <= 0;
				end
			else if(clk100Gen == 249) 
					begin
						clk100khz <= ~clk100khz;
						clk100Gen <= 0;
					end
					else clk100Gen <= clk100Gen + 1; 
		end
		
		
	//gera o clock de 1.632Mhz
	always@(posedge clk or negedge rst)
		begin
			if(~rst)
				begin
					clk160khzGen <= 0;
					clk160khz <= 0;
				end
			else if(clk160khzGen == 14) 
					begin
						clk160khz <= ~clk160khz;
						clk160khzGen <= 0;
					end
					else clk160khzGen <= clk160khzGen + 1; 
		end
		
		
	
	//gera o clock de 204khz
	always@(posedge clk or negedge rst)
		begin
			if(~rst)
				begin
					clk204khzGen <= 0;
					clk204khz <= 0;
				end
			else if(clk204khzGen == 122) 
					begin
						clk204khz <= ~clk204khz;
						clk204khzGen <= 0;
					end
					else clk204khzGen <= clk204khzGen + 1; 
		end
		
	
	
	//gera o clock de 800hz
	always@(posedge clk or negedge rst)
		begin
			if(~rst)
				begin
					clk800hzGen <= 0;
					clk800hz <= 0;
				end
			else if(clk800hzGen == 31249) 
					begin
						clk800hz <= ~clk800hz;
						clk800hzGen <= 0;
					end
					else clk800hzGen <= clk800hzGen + 1; 
		end

endmodule 