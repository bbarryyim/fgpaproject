// Copyright � 2009-2009 W. Craig Scratchley
// School of Engineering Science, SFU, BC, Canada  V5A 1S6
// Copying and distribution of this file, with or without modification,
//     are permitted in any medium without royalty provided the copyright
//     notice and this notice are preserved.

// Before load the commands written below will be executed

// fill user RAM with EE's

//fill $0800..$09ff $EE //too slow
pt bf 0800 09ff EE

