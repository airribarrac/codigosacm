double distPointLine(const point &a,const point &b, const point &pnt){
	double u=((pnt.x-a.x)*(b.x-a.x)+(pnt.y-a.y)*(b.y-a.y))/distsqr(a,b);
	point intersection;
	intersection.x=a.x+u*(b.x-a.x);
	intersection.y=a.y+u*(b.y-a.y);
	return dist(pnt,intersection);
}