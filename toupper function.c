// Note:
// - Total time of SPIParserExec() without any toupper process
//  	MSP: 450us
//		STM: 40us
//===============================================
// isupper version from Brad
// STM: 1.6us	
// MSP: 3.88us
	i = 0;
	while (cmdBuffer[i] != 0x00)
	{
		if (!isupper((int)cmdBuffer[i]))
		{
			// Uppercase character found
			cmdBuffer[i] = toupper(cmdBuffer[i]); 
		}
		i++;
	}

//==================================================
// port from Rabbit
// STM: 1.2us
// MSP: 2.2us
	bufLen = strlen(cmdBuffer);
	for(i=0;i<bufLen;i++)
	{
		cmdBuffer[i] = toupper(cmdBuffer[i]);
	}
//===================================================
// Modified Rabbit version (no strlen)
// STM: 1.2us
// MSP: 2.1us
	i = 0;
	while(cmdBuffer[i] != 0x00)
	{
		cmdBuffer[i] = toupper(cmdBuffer[i]);
		i++;
	}
//=================================================
// Custom function
// STM: 0.728us
// MSP: 1.9us
	i = 0;
	while(cmdBuffer[i] != 0x00)
	{
		// check if the char is upper case or not
		if(cmdBuffer[i] >= 0x61 && cmdBuffer[i] <= 0x7A)
		{
			// convert to upper case
			cmdBuffer[i] = cmdBuffer[i] - 0x20;
		}
		// next char
		i++;
	}	

	i = 0;
// Ensure cmdBuffer[i] is not null and cmdBuffer[i] does not equal the null terminator
while(cmdBuffer[i] != '\0' && i < MAX_BUFFER_SIZE)
{
    // check if the char is upper case or not
    if(cmdBuffer[i] >= 0x61 && cmdBuffer[i] <= 0x7A)
    {
        // convert to upper case
        cmdBuffer[i] = cmdBuffer[i] - 0x20;
    }
    // next char
    i++;
}
