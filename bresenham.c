#include<stdio.h>
#include<GL/glut.h>

int x1,y11,x2,y2;
int n;
int endpoints[8][4];

void draw_pixel(int x,int y)
{
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}

void draw_line(int x1,int y11,int x2,int y2)
{
	int dx,dy,i,p;
	int incx,incy,inc1,inc2;
	int x,y;
	dx=x2-x1;
	dy=y2-y11;
	if( dx < 0) dx=-dx;
	if(dy < 0) dy=-dy;
	incx=1;
	incy=1;
	x=x1;y=y11;
	if( x2 < x1) incx=-1;
	if( y2 < y11) incy=-1;
	if( dx > dy){
		draw_pixel(x,y);
		inc1=2*(dy-dx);
		inc2=2*dy;
		p=2*dy-dx;
		for(i=0;i<dx;i++){
			if(p>=0){
				y+=incy;
				p+=inc1;			
			}else{
				p+=inc2;
			}
			x+=incx;
			draw_pixel(x,y);
		}
		
	}
	else{
		draw_pixel(x,y);
		inc1=2*(dx-dy);
		inc2=2*dx;
		p=2*dx-dy;
		for(i=0;i<dy;i++){
			if(p>=0){
				x+=incx;
				p+=inc1;			
			}else{
				p+=inc2;
			}
			y+=incy;
			draw_pixel(x,y);
		}
	}


}

void drawText(int x, int y, char *s)
{
int i=0;
glColor3f(1.0,0.0,0.0);
glRasterPos2i(x,y);
for(i=0;s[i]!='\0';i++)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}

void bresnham(){
	int i;
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0;i<n;i++){
		x1=endpoints[i][0];y11=endpoints[i][1];x2=endpoints[i][2];y2=endpoints[i][3];
		draw_line(x1,y11,x2,y2);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2i(x1,y11);
			glVertex2i(x2,y2);
		glEnd();
		//printf("The points are %d %d %d %d\n",x1,y11,x2,y2);
		glFlush();
	}
	drawText(220,475,"Bresenham's Line Drawing Algo");
drawText(250,450,"Saaima Nishat , 1BI19CS133");
drawText(30,100,"(30,100)");
drawText(30,200,"(30,200)");
drawText(100,100,"(100,100)");
drawText(250,100,"(250,100)");
drawText(150,200,"(150,200)");
drawText(230,300,"(230,300)");
drawText(230,170,"(230,170)");
drawText(300,150,"(300,150)");
glFlush();

}

void myInit(){
	//glClearColor(1.0,1.0,1.0,1.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}


void main(int argc,char** argv){
	int i;
	printf("Enter number of lines:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the endpoints of line %d\n",i+1);
		scanf("%d%d%d%d",&endpoints[i][0],&endpoints[i][1],&endpoints[i][2],&endpoints[i][3]);	
	}
	
	//printf("Ener the endpoints of line segment");
	//scanf("%d%d%d%d",&x1,&y11,&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Bresenham line drawing");
	glutDisplayFunc(bresnham);
	myInit();
	glutMainLoop();


}

