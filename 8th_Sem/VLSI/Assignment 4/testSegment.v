module testSegment();

wire a,b,c,d,e,f,g;
reg D,B,C,A;

segment test(D,C,B,A,a,b,c,d,e,f,g);
initial
	begin
	D=1'b0; C=1'b0; B=1'b0; A=1'b0;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b0; C=1'b0; B=1'b0; A=1'b1;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b0; C=1'b0; B=1'b1; A=1'b0;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b0; C=1'b0; B=1'b1; A=1'b1;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b0; C=1'b1; B=1'b0; A=1'b0;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b0; C=1'b1; B=1'b0; A=1'b1;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b0; C=1'b1; B=1'b1; A=1'b0;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b0; C=1'b1; B=1'b1; A=1'b1;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b1; C=1'b0; B=1'b0; A=1'b0;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 D=1'b1; C=1'b0; B=1'b0; A=1'b1;
	$monitor("D:%b C:%b B:%b A:%b :: a:%b b:%b c:%b d:%b e:%b f:%b g:%b",D,C,B,A,a,b,c,d,e,f,g);
	#5 $finish;
	end
endmodule