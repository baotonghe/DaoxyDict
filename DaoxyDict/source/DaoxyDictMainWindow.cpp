#include "DaoxyDictMainWindow.h"

#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QListView>

#include "DaoxyQSSUtils.h"
#include "DaoxyDictHttpService.h"

static const QString c_strYoudaoAPI = QString("http://openapi.baidu.com/public/2.0/translate/dict/simple?"
                                              "client_id=VgW9huUl4d3cgpT7Tnp6aD8H&q=%1&from=en&to=zh");

DaoxyDictSearchBox::DaoxyDictSearchBox(QWidget *parent)
    : QLineEdit(parent)
{

}

DaoxyDictSearchBox::~DaoxyDictSearchBox()
{

}

DaoxyDictToolBar::DaoxyDictToolBar(QWidget *parent)
    : QWidget(parent)
{    
    // Create Toolbar Widget
    createToolBarWidget();

    // Init Search ComboBox
    initSearchComboBox();

    // Connect Signal And Slot
    connectSignalAndSlots();

    // Set ToolBar Layout
    QHBoxLayout *pMainLayout = new QHBoxLayout;
    pMainLayout->addWidget(m_pSearchEngine);
    pMainLayout->addWidget(m_pSearchBox);
    pMainLayout->addWidget(m_pSearchButton);
    setLayout(pMainLayout);

    // Set Style Sheet
    setStyleSheet(DaoxyQSSUtils::getStyleSheet("DaoxyDictToolBar"));
}

DaoxyDictToolBar::~DaoxyDictToolBar()
{

}

void DaoxyDictToolBar::onSearchButtonClick()
{   
    switch (m_pSearchEngine->currentData().toInt())
    {
    case emYoudao:
    {
        break;
    }
    case emBaidu:
    {
        DaoxyDictHttpService oHttpService;
        oHttpService.doRequestURL(c_strYoudaoAPI.arg(m_pSearchBox->text()));
        break;
    }
    case emJinshanCiba:
        break;
    default:
        break;
    }
}

void DaoxyDictToolBar::createToolBarWidget()
{
    m_pSearchEngine = new QComboBox(this);
    m_pSearchEngine->setObjectName("m_pSearchEngine");

    m_pSearchBox = new DaoxyDictSearchBox(this);
    m_pSearchBox->setObjectName("m_pSearchBox");

    m_pSearchButton = new QPushButton(this);
    m_pSearchButton->setText(tr("Search"));
    m_pSearchButton->setObjectName("m_pSearchButton");
}

void DaoxyDictToolBar::initSearchComboBox()
{
    m_pSearchEngine->addItem(tr("Youdao"), QVariant(emYoudao));
    m_pSearchEngine->addItem(tr("Baidu"), QVariant(emBaidu));
    m_pSearchEngine->addItem(tr("Ciba"), QVariant(emJinshanCiba));
}

void DaoxyDictToolBar::connectSignalAndSlots()
{
    connect(m_pSearchButton, SIGNAL(clicked()), this, SLOT(onSearchButtonClick()));
}

DaoxyDictMainWindow::DaoxyDictMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create MainWindow Widget
    createMainWindowWidget();

    // Set MainWindow Layout
    QVBoxLayout *pMainLayout = new QVBoxLayout;
    pMainLayout->addWidget(m_pToolBar);
    pMainLayout->addWidget(m_pListView);

    // Set Central Widget
    QWidget *pMainWidget = new QWidget(this);
    setCentralWidget(pMainWidget);
    pMainWidget->setLayout(pMainLayout);

    // Set MainWindow Style
    setFixedSize(500, 700);
    setStyleSheet(DaoxyQSSUtils::getStyleSheet("DaoxyDictMainWindow"));
    setWindowTitle(tr("Daoxy Dictionary"));
}

DaoxyDictMainWindow::~DaoxyDictMainWindow()
{

}

void DaoxyDictMainWindow::createMainWindowWidget()
{
    m_pToolBar = new DaoxyDictToolBar(this);
    m_pToolBar->setObjectName("m_pToolBar");

    m_pListView = new QListView(this);
    m_pListView->setObjectName("m_pListView");
}
