SELECT Dept_Code, MIN(Basic), MAX(Basic), AVG(Basic) FROM Emp GROUP BY Dept_Code;

SELECT Dept_Code, COUNT(*) FROM Emp WHERE Sex ='F' GROUP BY Dept_Code;

SELECT Dept_Code, City, COUNT(Emp_Code) from Emp GROUP BY Dept_Code, City;

SELECT Desig_code, COUNT(*) FROM Emp Where to_char(jn_dt,'dd/mm/yyyy') like '%/%/2000' group by desig_code order by count(*);

SELECT Dept_Code, SUM(Basic) from Emp where Sex='M' group by Dept_Code having Sum(Basic)>50000 order by sum(Basic) desc;

SELECT Emp_Name, Desig_Desc, Basic from Emp e, Designation d where e.Desig_Code = d.Desig_Code;

SELECT Emp_Name, Desig_Desc, Dept_Name, Basic from Emp e, Designation ds, Department dp where e.Desig_Code=ds.Desig_Code and e.Dept_Code = dp.Dept_Code;

SELECT Dept_Code from Department dp where (Select Count(*) from Emp where dp.Dept_Code = emp.Dept_Code)=0;

SELECT Dept_Name from Department dp where (Select count(*) from Emp where dp.Dept_Code = emp.Dept_Code) >= 1;

SELECT Dept_Name from Department dp where (Select count(*) from Emp where dp.Dept_Code = emp.Dept_Code) >= 10;

SELECT Dept_Code from Emp where Basic = (Select MAX(Basic) from Emp);

SELECT Desig_Desc from Designation ds, Emp e where e.Desig_Code = ds.Desig_Code and Basic = (Select MAX(Basic) from Emp);

SELECT Dept_Code, Count(Emp_Code) No_of_Managers from Emp e, Designation ds where e.Desig_Code = ds.Desig_Code and Desig_Desc = 'Manager' group by Dept_Code;

SELECT Basic Max_Basic from Emp where Basic >= ALL(Select Basic from Emp);  

SELECT distinct Basic Min_basic from Emp where Basic <= ALL(Select Basic from Emp);

SELECT Dept_Name from Department where Dept_Code = (Select Dept_Code from Emp group by Dept_Code having sum(Basic) = (Select MAX(SUM(Basic)) from Emp group by Dept_Code));

INSERT into EMP (EMP_CODE, EMP_NAME, DEPT_CODE, DESIG_CODE, SEX, ADDRESS, CITY, STATE, PIN, BASIC, JN_DT)
values('11','Honey','4','7','M','LakeTown','Kolkata','West Bengal','701233', 10000, '13-JUN-2016');

DELETE from Emp where Desig_Code NOT IN (Select Desig_Code from Designation);

SELECT Emp_Name from Emp E where Sex='F' AND Basic > (Select AVG(Basic) from Emp group by DEPT_CODE having Dept_Code = E.Dept_Code);

SELECT COUNT(Emp_Code) from Emp where Desig_Code='Manager' AND Sex = 'F';
