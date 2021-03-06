#include <QString>
#include <QPainter>
#include <qwt_dial.h>
#include <qwt_dial_needle.h>
#include <qwt_round_scale_draw.h>

class SpeedoMeter: public QwtDial
{
public:
    SpeedoMeter( QWidget *parent = NULL );

    void setLabel( const QString & );
    QString label() const;

protected:
    virtual void drawScaleContents( QPainter *painter,const QPointF &center, double radius ) const;

private:
    QString d_label;
};
