/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPVContourWidgetProperty.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2000-2001 Kitware Inc. 469 Clifton Corporate Parkway,
Clifton Park, NY, 12065, USA.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * Neither the name of Kitware nor the names of any contributors may be used
   to endorse or promote products derived from this software without specific 
   prior written permission.

 * Modified source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#include "vtkPVContourWidgetProperty.h"

#include "vtkObjectFactory.h"
#include "vtkPVApplication.h"
#include "vtkPVClassNameInformation.h"
#include "vtkPVProcessModule.h"
#include "vtkPVScalarRangeLabel.h"
#include "vtkPVSource.h"
#include "vtkPVWidget.h"

vtkStandardNewMacro(vtkPVContourWidgetProperty);
vtkCxxRevisionMacro(vtkPVContourWidgetProperty, "1.4");

void vtkPVContourWidgetProperty::SetAnimationTime(float time)
{
  if (this->NumberOfCommands > 1)
    {
    this->Scalars[1] = 0;
    this->Scalars[2] = time;
    }
  else
    {
    float scalars[3];
    scalars[0] = 1;
    scalars[1] = 0;
    scalars[2] = time;
    this->SetScalars(3, scalars);
    char **commands = new char *[2];
    int numScalars[2];
    numScalars[0] = 1;
    numScalars[1] = 2;
    commands[0] = new char[strlen(this->VTKCommands[0])+1];
    strcpy(commands[0], this->VTKCommands[0]);
    commands[1] = new char[9];
    sprintf(commands[1], "SetValue");
    this->SetVTKCommands(2, commands, numScalars);
    delete [] commands[0];
    delete [] commands[1];
    delete [] commands;
    }
  this->Widget->Reset();
}

void vtkPVContourWidgetProperty::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
