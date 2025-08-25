`timescale 1us/1ns
module _Modulador_FPGA_TB();

	reg clk;
	reg rst;
	reg Data;
	
	wire [7:0] countCtrl;

	_Data_Sampler _Data_Sampler_DUT
		(
			.clk(clk),
			.rst(rst),
			.Data(Data),
			.countCtrl(countCtrl)
		);
	
	
	initial	
		begin
			//reset
			rst = 1;
			#1 rst = 0;
			#1 rst = 1;
			
			Data = 1;
			
			//a conversao começa em
			#247;
			#21;
			Data = 0;
			#21;
			#21;
			Data = 1;
			#21;
			#21;
			#21;
			Data = 0;
			#21;
			#21;
			
			#100;
			$finish;
			
			//10011100 o que se espera ver no registro no fianal
		end
	
	//50KHz
	always #10 clk = ~clk;
	


endmodule 