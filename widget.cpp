#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <string>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(itemChangedSlot(QTreeWidgetItem*,int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{


    //QTreeWidget* treeWidget = new QTreeWidget(this);
    ui->treeWidget->clear();    //初始化树形控件
    ui-> treeWidget->setWindowTitle("QTreeWidget");
    //设定头项名称
    ui-> treeWidget->setHeaderLabels(QStringList()<<"Key"<<"Value");

    ui-> treeWidget->setSortingEnabled(true);
    ui-> treeWidget->header()->setSortIndicatorShown(true);//设置排序指示符是否显示
    // treeWidget->header()->setSortIndicator(0,Qt::AscendingOrder);//为第0列设置排序指示符为升序

    //定义第一个树形组
    QTreeWidgetItem* group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0,"group1");    //树形控件显示的文本信息
    group1->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);   //设置树形控件子项的属性
    group1->setCheckState(0,Qt::Unchecked); //初始状态没有被选中
    //第一组子项
    QTreeWidgetItem* subItem11 = new QTreeWidgetItem(group1);
    subItem11->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem11->setText(0,"subItem11");  //设置子项显示的文本
    subItem11->setText(1,"val");
    subItem11->setCheckState(0,Qt::Unchecked); //设置子选项的显示格式和状态

    QTreeWidgetItem* subItem111 = new QTreeWidgetItem(subItem11);
    subItem111->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem111->setText(0,"subItem11");  //设置子项显示的文本
    subItem111->setCheckState(0,Qt::Unchecked); //设置子选项的显示格式和状态

    QTreeWidgetItem* subItem112 = new QTreeWidgetItem(subItem11);
    subItem112->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem112->setText(0,"subItem11");  //设置子项显示的文本
    subItem112->setCheckState(0,Qt::Unchecked); //设置子选项的显示格式和状态

    QTreeWidgetItem* subItem113 = new QTreeWidgetItem(subItem112);
    subItem113->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem113->setText(0,"subItem11");  //设置子项显示的文本
    subItem113->setCheckState(0,Qt::Unchecked); //设置子选项的显示格式和状态

    QTreeWidgetItem* subItem114 = new QTreeWidgetItem(subItem112);
    subItem114->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem114->setText(0,"subItem11");  //设置子项显示的文本
    subItem114->setCheckState(0,Qt::Unchecked); //设置子选项的显示格式和状态

    QTreeWidgetItem* subItem12 = new QTreeWidgetItem(group1);
    subItem12->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem12->setText(0,"subItem12");
    subItem12->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem* subItem13 = new QTreeWidgetItem(group1);
    subItem13->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem13->setText(0,"subItem13");
    subItem13->setCheckState(0,Qt::Unchecked);

    //定义第二个树形组
    QTreeWidgetItem* group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0,"group2");
    group2->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    group2->setCheckState(0,Qt::Unchecked);

    //第二组子项
    QTreeWidgetItem* subItem21 = new QTreeWidgetItem(group2);   //指定子项属于哪一个父项
    subItem21->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem21->setText(0,"subItem21");
    subItem21->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem* subItem22 = new QTreeWidgetItem(group2);
    subItem22->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem22->setText(0,"subItem22");
    subItem22->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem* subItem23 = new QTreeWidgetItem(group2);
    subItem23->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    subItem23->setText(0,"subItem23");
    subItem23->setCheckState(0,Qt::Unchecked);
}


void Widget::itemChangedSlot(QTreeWidgetItem* item, int column)
{
    if(Qt::PartiallyChecked!=item->checkState(0))
        setChildCheckState(item,item->checkState(0));

    if(Qt::PartiallyChecked==item->checkState(0))
        if(!isTopItem(item))
            item->parent()->setCheckState(0,Qt::PartiallyChecked);
}


bool Widget::isTopItem(QTreeWidgetItem* item)
{
    if(!item) return false;
    if(!item->parent()) return true;
    return false;
}

void Widget::setChildCheckState(QTreeWidgetItem *item, Qt::CheckState cs)
{
    if(!item) return;
    for (int i=0;i<item->childCount();i++)
    {
        QTreeWidgetItem* child=item->child(i);
        if(child->checkState(0)!=cs)
        {
            child->setCheckState(0, cs);
        }
    }
    setParentCheckState(item->parent());
}

void Widget::setParentCheckState(QTreeWidgetItem *item)
{
    if(!item) return;
    int selectedCount=0;
    int childCount = item->childCount();
    for (int i=0;i<childCount;i++)
    {
        QTreeWidgetItem* child= item->child(i);
        if(child->checkState(0)==Qt::Checked)
        {
            selectedCount++;
        }
    }

    if(selectedCount == 0) {
        item->setCheckState(0,Qt::Unchecked);
    } else if (selectedCount == childCount) {
        item->setCheckState(0,Qt::Checked);
    } else {
        item->setCheckState(0,Qt::PartiallyChecked);
    }
}


void Widget::on_buttonSure_clicked()
{
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        if((*it)->checkState(0)==Qt::Checked){
            qDebug()<<(*it)->text(0);
        }
        ++it;
    }
}


