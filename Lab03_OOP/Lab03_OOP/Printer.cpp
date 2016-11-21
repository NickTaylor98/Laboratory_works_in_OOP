#include "stdafx.h"
#include "Printer.h"
void Printer::iAmPrinting(Kond_izd* izd)
{
	if (izd) (*izd).toConsole();
}