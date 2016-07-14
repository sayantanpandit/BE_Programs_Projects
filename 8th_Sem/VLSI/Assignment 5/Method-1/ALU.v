module mnor(x,y,z);

input [1:0] x;
input [1:0] y;
output [1:0] z;

assign z = ~(x|y);

endmodule

module mnand(x,y,z);

input [1:0] x;
input [1:0] y;
output [1:0] z;

assign z = ~(x&y);

endmodule

module MUX(I0,J0,I1,J1,I2,J2,I3,J3,S0,S1,Y,Z);

input [1:0] I0;
input [1:0] I1;
input [1:0] I2;
input [1:0] I3;

input J0;
input J1;
input J2;
input J3;

input S0;
input S1;
output [1:0] Y;
output Z;

assign Y[0] = ((!S0)&(!S1)&I0[0])|(S0&(!S1)&I1[0])|((!S0)&(S1)&(I2[0]))|(S0&S1&I3[0]); 

assign Y[1] = ((!S0)&(!S1)&I0[1])|(S0&(!S1)&I1[1]) | ((!S0)&(S1)&(I2[1])) | (S0&S1&I3[1]);

assign Z =   ((!S0)&(!S1)&J0)|(S0&(!S1)&J1) | ((!S0)&(S1)&J2) | (S0&S1&J3);

endmodule

module ALU(x,y,S0,S1,Output1,Output2);

input [1:0] x;
input [1:0] y;
input S0;
input S1; //select line

output [1:0] Output1;
output Output2;

reg [1:0] temp1 ;
reg [1:0] temp2 ; 
reg [1:0] temp3 ;
reg [1:0] temp4 ; 
wire [1:0] o1;
wire o2;
wire [1:0] o3;
wire o4;
wire [1:0] o5;
wire [1:0] o6;


fullAdder2bit u0 (x,y,o1,o2);
fullSubtractor2bit u1 (x,y,o3,o4);
mnor u3(x, y, o5);
mnand u4(x, y, o6);
MUX u5(o1, o2, o3, o4, o5, 1'bz, o6, 1'bz, S0,S1, Output1, Output2);

endmodule

