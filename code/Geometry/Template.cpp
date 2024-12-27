using Point = pair<ll, ll>;
Point operator + (Point p1, Point p2){ return {p1.X + p2.X, p1.Y + p2.Y}; }
Point operator - (Point p1, Point p2){ return {p1.X - p2.Y, p1.Y - p2.Y}; }
ll operator * (Point p1, Point p2){ return p1.X * p2.X + p1.Y * p2.Y; } // 내적
ll operator / (Point p1, Point p2){ return p1.X * p2.Y - p2.X * p1.Y; } // 외적
int Sign(ll v){ return (v > 0) - (v < 0); } // 양수면 +1, 음수면 -1, 0이면 0 반환
ll Dist(Point p1, Point p2){ return (p2 - p1) * (p2 - p1); } // 두 점 거리 제곱
ll SignedArea(Point p1, Point p2, Point p3){ return (p2 - p1) / (p3 - p1); }
int CCW(Point p1, Point p2, Point p3){ return Sign(SignedArea(p1, p2, p3)); }
