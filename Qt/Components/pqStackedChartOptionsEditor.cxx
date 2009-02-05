/*=========================================================================

   Program: ParaView
   Module:    pqStackedChartOptionsEditor.cxx

   Copyright (c) 2005-2008 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2. 

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

========================================================================*/

#include "pqStackedChartOptionsEditor.h"
#include "ui_pqStackedChartOptionsWidget.h"


class pqStackedChartOptionsEditorForm : public Ui::pqStackedChartOptionsWidget
{
public:
  pqStackedChartOptionsEditorForm();
  ~pqStackedChartOptionsEditorForm() {}
};


//-----------------------------------------------------------------------------
pqStackedChartOptionsEditorForm::pqStackedChartOptionsEditorForm()
  : Ui::pqStackedChartOptionsWidget()
{
}


//-----------------------------------------------------------------------------
pqStackedChartOptionsEditor::pqStackedChartOptionsEditor(QWidget *widgetParent)
  : pqOptionsPage(widgetParent)
{
  this->Form = new pqStackedChartOptionsEditorForm();
  this->Form->setupUi(this);

  // Listen for user changes.
  this->connect(this->Form->HelpFormat, SIGNAL(textChanged(const QString &)),
    this, SIGNAL(helpFormatChanged(const QString &)));
  this->connect(this->Form->Normalize, SIGNAL(toggled(bool)),
    this, SIGNAL(normalizationChanged(bool)));
  this->connect(this->Form->Gradient, SIGNAL(toggled(bool)),
    this, SIGNAL(gradientChanged(bool)));
}

pqStackedChartOptionsEditor::~pqStackedChartOptionsEditor()
{
  delete this->Form;
}

void pqStackedChartOptionsEditor::getHelpFormat(QString &format) const
{
  format = this->Form->HelpFormat->text();
}

void pqStackedChartOptionsEditor::setHelpFormat(const QString &format)
{
  this->Form->HelpFormat->setText(format);
}

bool pqStackedChartOptionsEditor::isSumNormalized() const
{
  return this->Form->Normalize->isChecked();
}

void pqStackedChartOptionsEditor::setSumNormalized(bool normalized)
{
  this->Form->Normalize->setChecked(normalized);
}

bool pqStackedChartOptionsEditor::isGradientDisplayed() const
{
  return this->Form->Gradient->isChecked();
}

void pqStackedChartOptionsEditor::setGradientDisplayed(bool gradient)
{
  this->Form->Gradient->setChecked(gradient);
}


