/* ============================================================================
* Copyright (c) 2009-2017 BlueQuartz Software, LLC
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this
* list of conditions and the following disclaimer.
*
* Redistributions in binary form must reproduce the above copyright notice, this
* list of conditions and the following disclaimer in the documentation and/or
* other materials provided with the distribution.
*
* Neither the name of BlueQuartz Software, the US Air Force, nor the names of its
* contributors may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* The code contained herein was partially funded by the followig contracts:
*    United States Air Force Prime Contract FA8650-07-D-5800
*    United States Air Force Prime Contract FA8650-10-D-5210
*    United States Prime Contract Navy N00173-07-C-2068
*
* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef _montecarlosimulation_ui_h_
#define _montecarlosimulation_ui_h_

#include "SIMPLib/Common/SIMPLibSetGetMacros.h"

#include "Modules/IModuleUI.h"
#include "Modules/MonteCarloSimulationModule/MonteCarloSimulationController.h"

#include "ui_MonteCarloSimulation_UI.h"

class QtSSettings;
class QSplashScreen;

class MonteCarloSimulation_UI : public IModuleUI, public Ui::MonteCarloSimulation_UI
{
    Q_OBJECT

  public:
    SIMPL_TYPE_MACRO(MonteCarloSimulation_UI)

    /**
     * @brief MonteCarloSimulation_UI
     * @param parent
     */
    MonteCarloSimulation_UI(QWidget* parent = 0);

    ~MonteCarloSimulation_UI();

    SIMPL_INSTANCE_PROPERTY(MonteCarloSimulationController*, Controller)

    /**
     * @brief readModuleSession
     * @param obj
     */
    void readModuleSession(QJsonObject &obj);

    /**
     * @brief writeModuleSession
     * @param obj
     */
    void writeModuleSession(QJsonObject &obj);

    /**
     * @brief validateData
     */
    bool validateData();

  protected:
    /**
     * @brief setupGui
     */
    void setupGui();

    /**
     * @brief changeEvent
     * @param event
     */
    void changeEvent(QEvent* event);

  protected slots:
    void on_mcModeCB_currentIndexChanged(int index);

    void slot_createMonteCarloBtn_clicked();

    void parametersChanged();

    void updateMCProgress(int loopCompleted, int totalLoops, float bseYield);

    void on_gpuPlatformCB_currentIndexChanged(int index);

  private slots:
    void threadFinished();

  private:
    QString                                                             m_LastFilePath = "";
    QSharedPointer<QFutureWatcher<void>>        m_Watcher;

    /**
     * @brief readCrystalSystemParameters
     * @param obj
     */
    void readMonteCarloParameters(QJsonObject &obj);

    /**
     * @brief readSpaceGroupParameters
     * @param obj
     */
    void readGPUParameters(QJsonObject &obj);

    /**
     * @brief writeCrystalSystemParameters
     * @param obj
     */
    void writeMonteCarloParameters(QJsonObject &obj);

    /**
     * @brief writeSpaceGroupParameters
     * @param obj
     */
    void writeGPUParameters(QJsonObject &obj);

    /**
     * @brief createValidators
     */
    void createValidators();

    /**
     * @brief createParametersChangedConnections
     */
    void createModificationConnections();

    /**
     * @brief createWidgetConnections
     */
    void createWidgetConnections();

    /**
     * @brief getCreationData
     * @return
     */
    MonteCarloSimulationController::MonteCarloSimulationData getCreationData();

    MonteCarloSimulation_UI(const MonteCarloSimulation_UI&);    // Copy Constructor Not Implemented
    void operator=(const MonteCarloSimulation_UI&);  // Operator '=' Not Implemented
};

#endif
