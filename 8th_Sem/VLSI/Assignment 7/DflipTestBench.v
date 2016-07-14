module DflipTestBench;

parameter CYCLE = 20;
reg clk,d;
wire q;

D_FF cut(q,d,clk);

always #(CYCLE/2)
	clk = ~clk;

initial begin
 	clk=1'b0;
	d = 1'b0;
	#CYCLE
	d = 1'b1;
	#CYCLE
	#CYCLE
	
	
	$display("Simulation ends");
	$stop;
end

endmodule


