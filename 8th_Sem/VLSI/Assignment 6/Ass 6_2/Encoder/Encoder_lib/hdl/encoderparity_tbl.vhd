-- VHDL Entity Encoder_lib.EncoderParity.symbol
--
-- Created:
--          by - cst.UNKNOWN (EC3)
--          at - 10:57:04 03-03-2016
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2010.3 (Build 21)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

ENTITY EncoderParity IS
   PORT( 
      D0 : IN     std_logic;
      D1 : IN     std_logic;
      D2 : IN     std_logic;
      D3 : IN     std_logic;
      V  : OUT    std_logic;
      X  : OUT    std_logic;
      Y  : OUT    std_logic
   );

-- Declarations

END EncoderParity ;

--
-- VHDL Architecture Encoder_lib.EncoderParity.tbl
--
-- Created:
--          by - cst.UNKNOWN (EC3)
--          at - 10:57:04 03-03-2016
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2010.3 (Build 21)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;
ARCHITECTURE tbl OF EncoderParity IS
   
      -- Architecture declarations
    

BEGIN

   -----------------------------------------------------------------
   truth_process_proc: PROCESS(D0, D1, D2, D3)
   -----------------------------------------------------------------
   BEGIN
      -- Block 1
      IF (D0 = '0') AND (D1 = '0') AND (D2 = '0') AND (D3 = '0') THEN
         V <= '0';
         X <= 'X';
         Y <= 'X';
      ELSIF (D0 = '1') AND (D1 = '0') AND (D2 = '0') AND (D3 = '0') THEN
         V <= '1';
         X <= '0';
         Y <= '0';
      ELSIF (D0 = 'X') AND (D1 = '1') AND (D2 = '0') AND (D3 = '0') THEN
         V <= '1';
         X <= '0';
         Y <= '1';
      ELSIF (D0 = 'X') AND (D1 = 'X') AND (D2 = '1') AND (D3 = '0') THEN
         V <= '1';
         X <= '1';
         Y <= '0';
      ELSIF (D0 = 'X') AND (D1 = 'X') AND (D2 = 'X') AND (D3 = '1') THEN
         V <= '1';
         X <= '1';
         Y <= '1';
      END IF;

   END PROCESS truth_process_proc;

-- Architecture concurrent statements
 

END tbl;
