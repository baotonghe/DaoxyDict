#ifndef DAOXYDICTMAINWINDOW_H
#define DAOXYDICTMAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QMainWindow>

class QPushButton;
class QComboBox;
class QListView;

enum DaoxySearchEngine
{
    emBaidu,
    emYoudao,
    emJinshanCiba
};

class DaoxyDictSearchBox : public QLineEdit
{
public:
    explicit DaoxyDictSearchBox(QWidget *parent = 0);
    ~DaoxyDictSearchBox();
};

class DaoxyDictToolBar : public QWidget
{
   Q_OBJECT
public:
    explicit DaoxyDictToolBar(QWidget *parent = 0);
    ~DaoxyDictToolBar();

private slots:
    void onSearchButtonClick();

private:
    void createToolBarWidget();
    void initSearchComboBox();
    void connectSignalAndSlots();

private:
    QComboBox *m_pSearchEngine;
    DaoxyDictSearchBox *m_pSearchBox;
    QPushButton *m_pSearchButton;
};

class DaoxyDictMainWindow : public QMainWindow
{
public:
    explicit DaoxyDictMainWindow(QWidget *parent = 0);
    ~DaoxyDictMainWindow();

private:
    void createMainWindowWidget();

private:
    DaoxyDictToolBar *m_pToolBar;
    QListView *m_pListView;
};

#endif // DAOXYDICTMAINWINDOW_H
