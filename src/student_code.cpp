#include "student_code.h"
#include "mutablePriorityQueue.h"

using namespace std;

namespace CGL
{

  /**
   * Evaluates one step of the de Casteljau's algorithm using the given points and
   * the scalar parameter t (class member).
   *
   * @param points A vector of points in 2D
   * @return A vector containing intermediate points or the final interpolated vector
   */
  std::vector<Vector2D> BezierCurve::evaluateStep(std::vector<Vector2D> const &points)
  { 
    // TODO Part 1.
    std::vector<Vector2D> interpolated;
    int i = 0;
    while (i < points.size() - 1) {
      Vector2D p = (1 - t) * points[i] + t * points[i+1];
      interpolated.push_back((1 - t) * points[i] + t * points[i+1]);
      i++;
    }
    return interpolated;
  }

  /**
   * Evaluates one step of the de Casteljau's algorithm using the given points and
   * the scalar parameter t (function parameter).
   *
   * @param points    A vector of points in 3D
   * @param t         Scalar interpolation parameter
   * @return A vector containing intermediate points or the final interpolated vector
   */
  std::vector<Vector3D> BezierPatch::evaluateStep(std::vector<Vector3D> const &points, double t) const
  {
    // TODO Part 2.
    std::vector<Vector3D> interpolated;
    int i = 0;
    while (i < points.size() - 1) {
      Vector3D p = (1 - t) * points[i] + t * points[i+1];
      interpolated.push_back((1 - t) * points[i] + t * points[i+1]);
      i++;
    }
    return interpolated;
  }

  /**
   * Fully evaluates de Casteljau's algorithm for a vector of points at scalar parameter t
   *
   * @param points    A vector of points in 3D
   * @param t         Scalar interpolation parameter
   * @return Final interpolated vector
   */
  Vector3D BezierPatch::evaluate1D(std::vector<Vector3D> const &points, double t) const
  {
    // TODO Part 2.
    std::vector<Vector3D> intermediate = evaluateStep(points, t);
    for (int i = 0; i < points.size()-2; i++) {
      intermediate = evaluateStep(intermediate, t);
    }
    return intermediate[0];
  }

  /**
   * Evaluates the Bezier patch at parameter (u, v)
   *
   * @param u         Scalar interpolation parameter
   * @param v         Scalar interpolation parameter (along the other axis)
   * @return Final interpolated vector
   */
  Vector3D BezierPatch::evaluate(double u, double v) const 
  {  
    // TODO Part 2.
    std::vector<Vector3D> u_bezier;
    for (int i = 0; i < controlPoints.size(); i++) {
      u_bezier.push_back(evaluate1D(controlPoints[i], u));
    }
    return evaluate1D(u_bezier, v);
  }
  

  Vector3D Vertex::normal( void ) const
  {
    // TODO Part 3.
    // Returns an approximate unit normal at this vertex, computed by
    // taking the area-weighted average of the normals of neighboring
    // triangles, then normalizing.
    HalfedgeCIter h = this->halfedge();
    Vector3D result;
    do {
      Vector3D v1 = h->vertex()->position;
      h = h->next();
      Vector3D v2 = h->vertex()->position;
      h = h->next();
      Vector3D v3 = h->vertex()->position;
      result += cross(v1-v2, v2-v3);
      h = h->twin();
    } while(h != this->halfedge());
    return result.unit();
  }

  EdgeIter HalfedgeMesh::flipEdge( EdgeIter e0 )
  {
    // TODO Part 4.
    // This method should flip the given edge and return an iterator to the flipped edge.
    HalfedgeIter h0 = e0->halfedge();
    HalfedgeIter twin0 = h0->twin();
    VertexIter b = h0->vertex();
    VertexIter c = twin0->vertex();
    HalfedgeIter h1 = h0->next();
    HalfedgeIter h2 = h1->next();
    VertexIter a = h2->vertex();
    HalfedgeIter twin1 = twin0->next();
    HalfedgeIter twin2 = twin1->next();
    VertexIter d = twin2->vertex();
    FaceIter f0 = h0->face();
    FaceIter f1 = twin0->face();
    EdgeIter ab = h2->edge();
    EdgeIter bd = twin1->edge();
    EdgeIter cd = twin2->edge();
    EdgeIter ac = h1->edge();

    a->halfedge() = h0;
    b->halfedge() = twin1;
    c->halfedge() = h1;
    d->halfedge() = twin0;
    
    ab->halfedge() = h2;
    bd->halfedge() = twin1;
    cd->halfedge() = twin2;
    ac->halfedge() = h1;
    e0->halfedge() = h0;
    
    f0->halfedge() = h0;
    f1->halfedge() = twin0;
    
    h0->setNeighbors(twin2, twin0, a, e0, f0);
    twin0->setNeighbors(h2, h0, d, e0, f1);
    h1->setNeighbors(h0, h1->twin(), c, ac, f0);
    h2->setNeighbors(twin1, h2->twin(), a, ab, f1);
    twin1->setNeighbors(twin0, twin1->twin(), b, bd, f1);
    twin2->setNeighbors(h1, twin2->twin(), d, cd, f0);
  
    return e0;
  }

  VertexIter HalfedgeMesh::splitEdge( EdgeIter e0 )
  {
    // TODO Part 5.
    // This method should split the given edge and return an iterator to the newly inserted vertex.
    // The halfedge of this vertex should point along the edge that was split, rather than the new edges.
    // Create new vertex m at the midpoint of edge e0
    
    HalfedgeIter h0 = e0->halfedge();
    HalfedgeIter twin0 = h0->twin();
    VertexIter b = h0->vertex();
    VertexIter c = twin0->vertex();
    HalfedgeIter h1 = h0->next();
    HalfedgeIter h2 = h1->next();
    VertexIter a = h2->vertex();
    HalfedgeIter twin1 = twin0->next();
    HalfedgeIter twin2 = twin1->next();
    VertexIter d = twin2->vertex();
    FaceIter f0 = h0->face();
    FaceIter f1 = twin0->face();
    EdgeIter e2 = h2->edge();
    EdgeIter e3 = twin1->edge();
    EdgeIter e4 = twin2->edge();
    EdgeIter e1 = h1->edge();
    
    VertexIter m = newVertex();
    m->position = (b->position + c->position) / 2.0;

    // Create the new halfedges
    HalfedgeIter new1 = newHalfedge();
    HalfedgeIter new2 = newHalfedge();
    HalfedgeIter new3 = newHalfedge();
    HalfedgeIter new4 = newHalfedge();
    HalfedgeIter new5 = newHalfedge();
    HalfedgeIter new6 = newHalfedge();

    // Create the new edges
    EdgeIter e5 = newEdge();
    EdgeIter e6 = newEdge();
    EdgeIter e7 = newEdge();
    
    // new faces
    FaceIter f2 = newFace();
    FaceIter f3 = newFace();

    // Update the vertex halfedge pointers
    m->halfedge() = new6;
    b->halfedge() = h0;
    c->halfedge() = twin0;
    a->halfedge() = new1;
    d->halfedge() = new4;

    // Update the existing edges
    e0->halfedge() = twin0;
    e1->halfedge() = h1;
    e2->halfedge() = h2;
    e3->halfedge() = twin1;
    e4->halfedge() = twin2;
    e5->halfedge() = new1;
    e6->halfedge() = new3;
    e7->halfedge() = new5;
    
    f0->halfedge() = h0;
    f1->halfedge() = twin0;
    f2->halfedge() = new6;
    f3->halfedge() = new4;

    h0->setNeighbors(new2, new5, b, e7, f0);
    twin0->setNeighbors(new3, new6, c, e0, f1);
    h1->setNeighbors(new1, h1->twin(), c, e1, f2);
    h2->setNeighbors(h0, h2->twin(), a, e3, f0);
    twin1->setNeighbors(new4, twin1->twin(), b, e3, f3);
    twin2->setNeighbors(twin0, twin2->twin(), d, e4, f1);
    new1->setNeighbors(new6, new2, a, e5, f2);
    new2->setNeighbors(h2, new1, m, e5, f0);
    new3->setNeighbors(twin2, new4, m, e6, f1);
    new4->setNeighbors(new5, new3, d, e6, f3);
    new5->setNeighbors(twin1, h0, m, e7, f3);
    new6->setNeighbors(h1, twin0, m, e0, f2);
    
    return m;
  }



  void MeshResampler::upsample( HalfedgeMesh& mesh )
  {
    // TODO Part 6.
    // This routine should increase the number of triangles in the mesh using Loop subdivision.
    // One possible solution is to break up the method as listed below.

    // 1. Compute new positions for all the vertices in the input mesh, using the Loop subdivision rule,
    // and store them in Vertex::newPosition. At this point, we also want to mark each vertex as being
    // a vertex of the original mesh.
    for (VertexIter v = mesh.verticesBegin(); v != mesh.verticesEnd(); v++) {
      std::cout << v->position << std::endl;
      Size n = v->degree();
      float u = (n == 3) ? 3.0 / 16.0 : 3.0 / (8.0 * n);
      Vector3D original_position = v->position;
      Vector3D original_neighbor_position_sum = Vector3D();

      HalfedgeIter h = v->halfedge();
      do {
        original_neighbor_position_sum += h->twin()->vertex()->position;
        h = h->twin()->next();
      } while (h != v->halfedge());

      v->newPosition = (1 - n * u) * original_position + u * original_neighbor_position_sum;
      std::cout << v->newPosition << std::endl;
      v->isNew = false;
    }
    
    // 2. Compute the updated vertex positions associated with edges, and store it in Edge::newPosition.
    for (EdgeIter e = mesh.edgesBegin(); e != mesh.edgesEnd(); e++) {
      std::cout << e->length() << std::endl;
      e->isNew = false;
      Vector3D A = e->halfedge()->vertex()->position;
      Vector3D B = e->halfedge()->twin()->vertex()->position;
      Vector3D C = e->halfedge()->next()->next()->vertex()->position;
      Vector3D D = e->halfedge()->twin()->next()->next()->vertex()->position;

      Vector3D newPosition = 3.0 / 8.0 * (A + B) + 1.0 / 8.0 * (C + D);
      std::cout << newPosition << std::endl;
      e->newPosition = newPosition;
//      VertexIter newVertex = mesh.newVertex();
//      newVertex->newPosition = newPosition;
//      newVertex->isNew = true;
    }
    
    // 3. Split every edge in the mesh, in any order. For future reference, we're also going to store some
    // information about which subdivide edges come from splitting an edge in the original mesh, and which edges
    // are new, by setting the flat Edge::isNew. Note that in this loop, we only want to iterate over edges of
    // the original mesh---otherwise, we'll end up splitting edges that we just split (and the loop will never end!)
    vector<EdgeIter> newEdges;
    for (EdgeIter e = mesh.edgesBegin(); e != mesh.edgesEnd(); e++) {
      if (!e->isNew) {
        std::cout << e->halfedge()->vertex()->position << std::endl;
        VertexIter newVertex = mesh.splitEdge(e);
        newVertex->newPosition = e->newPosition;
        newVertex->isNew = true;
        EdgeIter e1 = newVertex->halfedge()->edge();
        EdgeIter e2 = newVertex->halfedge()->twin()->next()->edge();
        EdgeIter e3 = newVertex->halfedge()->next()->next()->edge();
        EdgeIter e4 = newVertex->halfedge()->twin()->next()->twin()->next()->edge();
        
        e1->isNew = true;
        e2->isNew = true;
        e3->isNew = true;
        e4->isNew = true;
        
        newEdges.push_back(e2);
        newEdges.push_back(e3);
      }
    }
    
    // 4. Flip any new edge that connects an old and new vertex.
    for (EdgeIter e = mesh.edgesBegin(); e != mesh.edgesEnd(); e++) {
      if (e->isNew && (std::find(newEdges.begin(), newEdges.end(), e) != newEdges.end())) {
        if ((e->halfedge()->vertex()->isNew != e->halfedge()->twin()->vertex()->isNew)) {
          mesh.flipEdge(e);
        }
      }
    }
    
    // 5. Copy the new vertex positions into final Vertex::position.
    for (VertexIter v = mesh.verticesBegin(); v != mesh.verticesEnd(); v++) {
      v->position = v->newPosition;
    }
  }
}
