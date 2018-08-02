#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTreeWidgetItem>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public: //申明初始化函数
    void init();
    void setChildCheckState(QTreeWidgetItem *item, Qt::CheckState cs);
    void setParentCheckState(QTreeWidgetItem *item);
public slots:   //申明信号与槽,当树形控件的子选项被改变时执行
    void itemChangedSlot(QTreeWidgetItem* item , int column);
    bool isTopItem(QTreeWidgetItem* item);
    void on_buttonSure_clicked();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
