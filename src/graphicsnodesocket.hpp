/* See LICENSE file for copyright and license details. */

#ifndef GRAPHICS_NODE_SOCKET_H
#define GRAPHICS_NODE_SOCKET_H

#include <QtCore/QString>
#include <QtCore/QPointF>
#include <QtCore/QSizeF>

#include "graphicsnodedefs.hpp"

class QGraphicsSceneMouseEvent;
class QGraphicsSceneDragDropEvent;
class GraphicsDirectedEdge;

class GraphicsNode;

class GraphicsNodeSocketPrivate;

/**
* visual representation of a socket. the visual representation consists of a
* circle for User Interaction and a label
*/
class GraphicsNodeSocket : public QObject
{
    Q_OBJECT
    friend class GraphicsDirectedEdge; // could be removed once the model is ready
    friend class GraphicsNode; // For the constructor
    friend class GraphicsNodePrivate; // for notifyPositionChange //TODO remove
    friend class GraphicsDirectedEdgePrivate; // could be removed once the model is ready
    friend class GraphicsNodeView; //for the view helpers, could be removed
public:
    /*
    * the socket comes in two flavors: either as sink or as source for a
    * data stream
    */
    enum class SocketType
    {
        SINK,
        SOURCE
    };

    GraphicsDirectedEdge *edge() const;
    void setEdge(GraphicsDirectedEdge *edge);

    QString text() const;
    void setText(const QString& text);

    SocketType socketType() const;

    bool isSink() const; //TODO get rid of those socketType is enough
    bool isSource() const;

    QSizeF size() const;
    QSizeF minimalSize() const;

    QGraphicsItem *graphicsItem() const;

    GraphicsNode *source() const;
    GraphicsNode *sink() const;

Q_SIGNALS:
    void connectedTo(GraphicsNodeSocket* other);

private:
    explicit GraphicsNodeSocket(SocketType socket_type, GraphicsNode *parent = nullptr);
    GraphicsNodeSocket(SocketType socket_type, const QString &text, GraphicsNode *parent = nullptr,QObject *data=0,int index=0);

    GraphicsNodeSocketPrivate* d_ptr;
    Q_DECLARE_PRIVATE(GraphicsNodeSocket)
};
Q_ENUMS(GraphicsNodeSocket::SocketType)

#endif /* __GRAPHICSNODESOCKET_HPP__99275D3E_35A8_4D63_8E10_995E5DC83C8C */

