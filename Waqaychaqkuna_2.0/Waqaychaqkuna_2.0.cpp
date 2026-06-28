#include "pch.h"
#include "FrmMenu.h"
#include "FrmNivel1.h"
#include "FrmNivel2.h"

using namespace System;
using namespace Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Waqaychaqkuna20::FrmNivel2());
    return 0;
}
