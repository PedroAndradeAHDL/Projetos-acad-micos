module _First_Clock_Reset
(
	input Clk,
	
	output rst
	//output reg sig
);

	reg rst01;
	reg rst02;
	reg [1:0] cntrst;
	reg aux;
	
	assign rst = ~rst01 & ~rst02;

		//criando reset via first clock
	always@(posedge Clk or negedge rst02)
		begin
			if(~rst02) rst01 <= 0;
			else rst01 <= 1;
		end



	//criando reset via first clock
	always@(Clk)
		begin
			if(~Clk)
				begin
					if((cntrst >= 0) & (cntrst <= 3)) cntrst = cntrst + 1;
					else cntrst <= 0;
				end else
						begin
							if(cntrst == 2)
								begin
									rst02 <= 0;
									aux <= 1;
								end
							else if(aux != 1) rst02 <= 1;
									else rst02 <= 0;
						end
		end
		
		
	/*always@(posedge rst)
		begin
			sig <= 0;
		end*/

endmodule 