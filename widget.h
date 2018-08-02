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
    void updateParentItem(QTreeWidgetItem* item);

public slots:   //申明信号与槽,当树形控件的子选项被改变时执行
    void treeItemChanged(QTreeWidgetItem* item , int column);
    void on_buttonSure_clicked();
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
