#include "pch.h"
#include "FrmMenu.h"

using namespace System;
using namespace Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Waqaychaqkuna20::FrmMenu());
    return 0;
}
