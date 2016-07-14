-- VHDL Entity NAND_lib.NAND_Gate.symbol
--
-- Created:
--          by - cst.UNKNOWN (EC3)
--          at - 10:54:59 21-01-2016
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2010.3 (Build 21)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

ENTITY NAND_Gate IS
   PORT( 
      A : IN     std_logic;
      B : IN     std_logic;
      C : OUT    std_logic
   );

-- Declarations

END NAND_Gate ;

--
-- VHDL Architecture NAND_lib.NAND_Gate.tbl
--
-- Created:
--          by - cst.UNKNOWN (EC3)
--          at - 10:54:59 21-01-2016
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2010.3 (Build 21)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
ARCHITECTURE tbl OF NAND_Gate IS
   
      -- Architecture declarations
    

BEGIN

   -----------------------------------------------------------------
   truth_process_proc: PROCESS(A, B)
   -----------------------------------------------------------------
   BEGIN
      -- Block 1
      IF (A = '0') AND (B = '0') THEN
         C <= '1';
      ELSIF (A = '0') AND (B = '1') THEN
         C <= '1';
      ELSIF (A = '1') AND (B = '0') THEN
         C <= '1';
      ELSIF (A = '1') AND (B = '1') THEN
         C <= '0';
      END IF;

   END PROCESS truth_process_proc;

-- Architecture concurrent statements
 

END tbl;
