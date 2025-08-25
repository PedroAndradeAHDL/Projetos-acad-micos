module LUT_Access
(
	input clk,
	input rst,
	
	output wire [14:0] out
);
	//	geração do clock interno
	reg [14:0] cnt_clk;
	reg in_clk;
	reg [10:0] addr;
	
//	instancia da ROM
	CosLookUpTable	CosLookUpTable_inst (
		.address(addr),
		.clock(clk),
		.q(out)
		);

	
	
	//	gera o clock interno
	always@(posedge clk or negedge rst)
		begin
			if(!rst)
				begin
					in_clk <= 0;
					cnt_clk <= 0;
				end
			else	
				begin
					cnt_clk <= cnt_clk + 1;
					
					if(cnt_clk == 24999) 
						begin
							in_clk <= ~in_clk;
							cnt_clk <= 0;
						end
				end
		end
		
		

	//	incrementa os endereços
	 always@(posedge in_clk or negedge rst)
		begin
			if(!rst) addr <= 1100;
			else
				begin
					addr <= addr + 1;
					
					if(addr == 2000) addr <= 0;
				end
		end
		
		


endmodule 