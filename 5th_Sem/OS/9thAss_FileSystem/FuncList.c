//    $myfs 
//    myfs> 
//    myfs>mkfs osfile1 512 10MB 
//    myfs>mkfs osfile2 1024 20MB 
//    myfs>use osfile1 as C: 
//    myfs>use osfile2 as D: /* the filesystem on osfile2 will henceforth be accessed as D: */
    myfs>cp osfile3 C:tesfile1 /* copy the file osfile3 from os to the filesystem C: as testfile1 */
//    myfs>ls C: /* see the contents of the filesystem C: */
    testfile1 ... size
    myfs>cp C:tesfile1 C:testfile1a /* copy the file testfile1 from C: to the filesystem C: as testfile1a */
    myfs>ls C: /* see the contents of the filesystem C: */
    testfile1 ... size
    testfile1a ... size
    myfs>cp C:tesfile1 D:testfile2 /* copy the file testfile1 from C: to the filesystem D: as testfile2 */
    myfs>cp D:testfile2 osfile4 /* copy the file testfile2 from C: to the to the OS as osfile4 */
    myfs>rm C:testfile1 /* Delete the testfile1 from C: */
    myfs>ls C: /* see the contents of the filesystem C: */
    testfile1a ... size
    myfs>mv D:testfile2 D:testfile2a  /* Rename  testfile2 of D: to testfile2a in D: */
    myfs>exit /* exit from your program */
    $diff osfile3 osfile4 /* see the difference between osfile3 and osfile4 */

