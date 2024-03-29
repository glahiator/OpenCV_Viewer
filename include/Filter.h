#ifndef FILTER_H
#define FILTER_H

#include <QQuickPaintedItem>
#include <QString>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QImage>
#include <QMatrix4x4>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/base.hpp>

class Filter : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString filename WRITE setFilename NOTIFY filenameChanged MEMBER filename)
    Q_PROPERTY(int imgHeight  NOTIFY imgHeightChanged MEMBER m_imgHeight)
    Q_PROPERTY(int imgWidth  NOTIFY imgHeightChanged MEMBER m_imgWidth)

public:
    Filter(QQuickItem *item = nullptr);
    void preparePaint();
    void paint(QPainter * painter);
    Q_INVOKABLE void resetImage( );
    Q_INVOKABLE void filter2DImage(QMatrix4x4 _m);
    Q_INVOKABLE void sobelDeriv( int xorder, int yorder, int ksize, double scale, double delta );
    Q_INVOKABLE void scharrDeriv( int xorder, int yorder, double scale, double delta );
    Q_INVOKABLE void laplacianDeriv(int ksize, double scale, double delta);
    Q_INVOKABLE void morphologyEx(int op, int iterations, int shape, int _ks);
    Q_INVOKABLE void applyColorMap(int colorMap);
    Q_INVOKABLE void pyrDown();
    Q_INVOKABLE void pyrUp();

    void setFilename( QString _fn );

    QImage draw_img;
    cv::Mat src_frame;
    cv::Mat dst_frame;
    QString filename;

    int m_imgHeight;
    int m_imgWidth;

signals:
    void filenameChanged( QString _fn );
    void imgHeightChanged();
    void imgWidthChanged();
};

#endif // FILTER_H
