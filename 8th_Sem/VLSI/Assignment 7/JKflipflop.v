//JK flip-flop from D flip-flop and gates   
module JKFF (Q,J,K,CLK);
output Q;
input J,K,CLK,RST;
wire JK;
assign JK = (J & ~Q) | (~K & Q);
//Instantiate D flipflop
DFF JK1 (Q,JK,CLK);
endmodule