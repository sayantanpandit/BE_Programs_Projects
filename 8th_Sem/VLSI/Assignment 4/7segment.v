module Seven_segment(input A, B, C, D, output [0:6] out);
assign out[0] = C | A | (B & D) | (~B & ~D);
assign out[1] = ~B | ( C & D) |( ~C & ~D);
assign out[2] = ~C | D | B;
assign out[3] =  A | (C & ~D) | (~B & C) |(~B & ~D) |(B &~C &D);
assign out[4] =  (C & ~D) | (~B & ~D);
assign out[5] = A | (~C & ~D) | (B & ~D) |( B & ~C);
assign out[6] = A | (C & ~D) | (~B & C) | (B& ~C);
endmodule
module test_seven_segment(input [0:3] in, output [0:6] display);
assign in = 4'b0011;
Seven_segment segment ( in[0], in[1], in[2], in[3] , display);
endmodule
