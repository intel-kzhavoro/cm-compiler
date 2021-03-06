/*
 * Copyright (c) 2017, Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "ScanPreProcess.h"
#include "CmdParser.h"

using namespace std;

/*********************************************************************************************************************************/

int main(int argc, char* argv[])
{
   CmTask   *SppTask = NULL;

   if (!ParseCommandLine(argc, argv))
      return 0;

   ScanPreProcess *scanpp = new ScanPreProcess();

   scanpp->Init();

   if (scanpp->GetInputImage(FLAGS_i.c_str()) < 0)
   {
      throw std::runtime_error(std::string("Error in GetInputImage - input file not found"));
   }

   scanpp->AssemblerGraph(SppTask, FLAGS_skewangle, FLAGS_sppbits);

   scanpp->ExecuteGraph(SppTask, FLAGS_maxframes);

   scanpp->SaveOutputImage(FLAGS_o.c_str(), FLAGS_skewangle);

   return 0;
}
