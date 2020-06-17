void main()
{
  //Enable port D clocking
  //*(unsigned long*)(0x40023830) |= 0x8
  *(unsigned long*)(0x40021014) |= 0x00200000;  // Done
  
  //little delay for GPIOD get ready
  volatile unsigned long i=0;                   // Done
  i++; i++; i++;                                // Done
  i=0;                                          // Done
  
  //Set PD13 as General purpose output          // Done
  //*(unsigned long*)(0x40020C00) = (*(unsigned long*)(0x40020C00)& (~0x0C000000)) | (0x0000000);
  *(unsigned long*)(0x48001000) = (*(unsigned long*)(0x48001000)& (~0x000C0000)) | (0x00040000); //Done
  
//  //Turn LED ON!
//  *(unsigned long*)(0x48001014) |= 0x0200;      // Done

//    while(1);
  while(1){
     *(unsigned long*)(0x48001014) |= 0x0200;
    for( i=0; i<1000000 ;++i );
    //Turn LED OFF
    *(unsigned long*)(0x48001014) &= ~0x0200;
    //Delay
    for( i=0; i<1000000 ;++i );
  }
}