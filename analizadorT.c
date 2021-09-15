#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]){
	unsigned char t[20][125]={
		/* TRAMA 1 */
		{
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x04, /* .F...... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x01, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, /* .F....9. */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, /* ........ */
		0x39, 0xfe                                      /* 9. */
		},

		/*TRAMA 2 */
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x01, /* E....... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x02, 0x00, 0x1f, /* ........ */
		0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x39, 0xfe, /* E.....9. */
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
		0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00                          /* .... */
		},

		/* TRAMA 3 */
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x46, 0x00, /* .F....F. */
		0x80, 0x42, 0x04, 0x55, 0x34, 0x11, 0x80, 0x11, /* .B.U4... */
		0x6b, 0xf0, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* k...9... */
		0x67, 0x02, 0xaa, 0xbb, 0xcc, 0xdd, 0x04, 0x0c, /* g....... */
		0x00, 0x35, 0x00, 0x2e, 0x85, 0x7c, 0xe2, 0x1a, /* .5...|.. */
		0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x03, 0x77, 0x77, 0x77, 0x03, 0x69, /* ...www.i */
		0x73, 0x63, 0x05, 0x65, 0x73, 0x63, 0x6f, 0x6d, /* sc.escom */
		0x03, 0x69, 0x70, 0x6e, 0x02, 0x6d, 0x78, 0x00, /* .ipn.mx. */
		0x00, 0x1c, 0x00, 0x01                          /* .... */
		},

		/* TRAMA 4 */
		{
		0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, /* ........ */
		0xb3, 0x9c, 0xae, 0xba, 0x00, 0x04, 0xf0, 0xf0, /* ........ */
		0x01, 0xc9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x9b, 0x6d  /* .....|.m */
		},

		/* TRAMA 5 */
		{
		0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x06, 0x00, 0x10, /* .F...... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x23, /* .......# */
		0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, 0x39, 0xcb, /* .F....9. */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x94, 0xcc, /* ........ */
		0x3a, 0xe1                                      /* :. */
		},

		/* TRAMA 6*/
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x06, 0x00, 0x10, /* E....... */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x04, 0x00, 0x1f, /* ........ */
		0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, /* E.....:. */
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
		0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00                          /* .... */
		},

		/* TRAMA 7 */
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x08, 0x00, 0x45, 0x00, /* E.....E. */
		0x00, 0x6f, 0x90, 0x30, 0x40, 0x00, 0xfb, 0x11, /* .o.0@... */
		0x24, 0xe7, 0x94, 0xcc, 0x67, 0x02, 0x94, 0xcc, /* $...g... */
		0x39, 0xcb, 0x00, 0x35, 0x04, 0x0c, 0x00, 0x5b, /* 9..5...[ */
		0xe8, 0x60, 0xe2, 0x1a, 0x85, 0x80, 0x00, 0x01, /* .`...... */
		0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x03, 0x77, /* .......w */
		0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, /* ww.isc.e */
		0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, /* scom.ipn */
		0x02, 0x6d, 0x78, 0x00, 0x00, 0x1c, 0x00, 0x01, /* .mx..... */
		0xc0, 0x14, 0x00, 0x06, 0x00, 0x01, 0x00, 0x00, /* ........ */
		0x0e, 0x10, 0x00, 0x21, 0x04, 0x64, 0x6e, 0x73, /* ...!.dns */
		0x31, 0xc0, 0x1a, 0x03, 0x74, 0x69, 0x63, 0xc0, /* 1...tic. */
		0x1a, 0x77, 0xec, 0xdf, 0x29, 0x00, 0x00, 0x2a, /* .w..)..* */
		0x30, 0x00, 0x00, 0x0e, 0x10, 0x00, 0x12, 0x75, /* 0......u */
		0x00, 0x00, 0x00, 0x2a, 0x30                    /* ...*0 */
		},

		/* TRAMA 8 */
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
		0x02, 0x03, 0x04, 0x05, 0x08, 0x00, 0x45, 0x00, /* .F....E. */
		0x00, 0x42, 0x04, 0x56, 0x00, 0x00, 0x80, 0x11, /* .B.V.... */
		0x6b, 0xef, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* k...9... */
		0x67, 0x02, 0x04, 0x0c, 0x00, 0x35, 0x00, 0x2e, /* g....5.. */
		0xff, 0x87, 0x68, 0x2a, 0x01, 0x00, 0x00, 0x01, /* ..h*.... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x77, /* .......w */
		0x77, 0x77, 0x03, 0x69, 0x73, 0x63, 0x05, 0x65, /* ww.isc.e */
		0x73, 0x63, 0x6f, 0x6d, 0x03, 0x69, 0x70, 0x6e, /* scom.ipn */
		0x02, 0x6d, 0x78, 0x00, 0x00, 0x01, 0x00, 0x01  /* .mx..... */
		},

		/* TRAMA 9 */
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x23, /* ..E....# */
		0x8b, 0x46, 0xe9, 0xad, 0x08, 0x00, 0x45, 0x00, /* .F....E. */
		0x00, 0x3c, 0x04, 0x57, 0x00, 0x00, 0x80, 0x01, /* .<.W.... */
		0x98, 0x25, 0x94, 0xcc, 0x39, 0xcb, 0x94, 0xcc, /* .%..9... */
		0x3a, 0xe1, 0x08, 0x00, 0x49, 0x5c, 0x03, 0x00, /* :...I\.. */
		0x01, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, /* ..abcdef */
		0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, /* ghijklmn */
		0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, /* opqrstuv */
		0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, /* wabcdefg */
		0x68, 0x69                                      /* hi */
		},

		/* TRAMA 10 */
		{
		0x00, 0x02, 0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x02, /* ........ */
		0x02, 0x03, 0x04, 0x05, 0x00, 0x04, 0xf0, 0xf0, /* ........ */
		0x0c, 0xc7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x9b, 0x6d  /* .....|.m */
		},

		/* trama 11 */
		{
		0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x11, 0x11, /* ........ */
		0x11, 0x11, 0x11, 0x11, 0x00, 0x03, 0xf0, 0xf0, /* ........ */
		0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d  /* ....C..m */
		},

		/* trama 12 */
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x02, 0x03, 0x04, 0x05, 0x08, 0x00, 0x45, 0x00, /* E.....E. */
		0x00, 0x3c, 0x01, 0xb5, 0x00, 0x00, 0x3f, 0x01, /* .<....?. */
		0xdb, 0xc7, 0x94, 0xcc, 0x3a, 0xe1, 0x94, 0xcc, /* ....:... */
		0x39, 0xcb, 0x00, 0x00, 0x51, 0x5c, 0x03, 0x00, /* 9...Q\.. */
		0x01, 0x00, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, /* ..abcdef */
		0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, /* ghijklmn */
		0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, /* opqrstuv */
		0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, /* wabcdefg */
		0x68, 0x69                                      /* hi */
		},

		/* trama 13 */
		{
		0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x01, /* ........ */
		0x02, 0x03, 0x04, 0x05, 0x00, 0x03, 0xf0, 0xf1, /* ........ */
		0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d  /* ....C..m */
		},

		/* trama 14 */
		{
		0x00, 0x1f, 0x45, 0x9d, 0x1e, 0xa2, 0x00, 0x1c, /* ..E..... */
		0xc0, 0x7b, 0x35, 0xa1, 0x08, 0x00, 0x48, 0x00, /* .{5...H. */
		0x00, 0x48, 0x5c, 0x7d, 0x00, 0x00, 0x80, 0x01, /* .H\}.... */
		0x6c, 0x88, 0x94, 0xcc, 0x39, 0xc3, 0x94, 0xcc, /* l...9... */
		0x00, 0x49, 0x07, 0x0b, 0x04, 0x00, 0x00, 0x00, /* .I...... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, /* ........ */
		0x3b, 0x5c, 0x02, 0x00, 0x10, 0x00, 0x61, 0x62, /* ;\....ab */
		0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, /* cdefghij */
		0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, /* klmnopqr */
		0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63, /* stuvwabc */
		0x64, 0x65, 0x66, 0x67, 0x68, 0x69              /* defghi */
		},

		/* trama 15*/
		{
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x00, 0x1f, /* .#.F.... */
		0x45, 0x9d, 0x1e, 0xa2, 0x80, 0x35, 0x00, 0x01, /* E....5.. */
		0x08, 0x00, 0x06, 0x04, 0x00, 0x03, 0x00, 0x1f, /* ........ */
		0x45, 0x9d, 0x1e, 0xa2, 0x94, 0xcc, 0x3a, 0xe1, /* E.....:. */
		0x00, 0x23, 0x8b, 0x46, 0xe9, 0xad, 0x94, 0xcc, /* .#.F.... */
		0x39, 0xcb, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 9....... */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0xd8, 0xee, 0xdf, 0xb0  /* ........ */
		},

		/* trama 16 */
		{
		0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x22, 0x22, /* ........ */
		0x22, 0x22, 0x22, 0x22, 0x00, 0x03, 0xf0, 0xf0, /* ........ */
		0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d  /* ....C..m */
		},

		/*trama 17 */
		{
		0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, /* ........ */
		0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf0, /* ........ */
		0x53, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x43, 0x05, 0x90, 0x6d  /* ....C..m */
		},

		/* trama 18 */
		{
		0x02, 0xff, 0x53, 0xc3, 0xe9, 0xab, 0x00, 0xff, /* ..S..... */
		0x66, 0x7f, 0xd4, 0x3c, 0x08, 0x00, 0x45, 0x00, /* f..<..E. */
		0x00, 0x30, 0x2c, 0x00, 0x40, 0x00, 0x80, 0x06, /* .0,.@... */
		0x4b, 0x74, 0xc0, 0xa8, 0x01, 0x02, 0xc0, 0xa8, /* Kt...... */
		0x01, 0x01, 0x04, 0x03, 0x00, 0x15, 0x00, 0x3b, /* .......; */
		0xcf, 0x44, 0x00, 0x00, 0x00, 0x00, 0x70, 0x20, /* .D....p  */
		0x20, 0x00, 0x0c, 0x34, 0x00, 0x00, 0x02, 0x04, /*  ..4.... */
		0x05, 0xb4, 0x01, 0x01, 0x04, 0x02              /* ...... */
		},

		/*trama 19 */
		{
		0x00, 0x02, 0xb3, 0x9c, 0xae, 0xba, 0x00, 0x02, /* ........ */
		0xb3, 0x9c, 0xdf, 0x1b, 0x00, 0x03, 0xf0, 0xf1, /* ........ */
		0x53, 0x0b, 0x0e, 0x00, 0xff, 0xef, 0x14, 0x00, /* ........ */
		0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x7f, 0x23, /* ..(....# */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
		0x00, 0x00, 0x00, 0x00, 0x01, 0x99, 0x98, 0x6d  /* .......m */
		},
		/* trama 20 */
		{
		0x00, 0xff, 0x66, 0x7f, 0xd4, 0x3c, 0x02, 0xff, /* ..f..<.. */
		0x53, 0xc3, 0xe9, 0xab, 0x08, 0x00, 0x45, 0x00, /* S.....E. */
		0x00, 0x30, 0x05, 0xc4, 0x40, 0x00, 0x80, 0x06, /* .0..@... */
		0x71, 0xb0, 0xc0, 0xa8, 0x01, 0x01, 0xc0, 0xa8, /* q....... */
		0x01, 0x02, 0x00, 0x15, 0x04, 0x03, 0x21, 0x5d, /* ......!] */
		0x3a, 0x44, 0x00, 0x3b, 0xcf, 0x45, 0x70, 0x12, /* :D.;.Ep. */
		0x44, 0x70, 0x8c, 0x11, 0x00, 0x00, 0x02, 0x04, /* Dp...... */
		0x05, 0xb4, 0x01, 0x01, 0x04, 0x02              /* ...... */
		}};	
	unsigned char ts[][5]={"RR","RNR","REJ","SREJ"};
	unsigned char com[][8]={"UI","SIM","-","SARM","UP",
							"-","-","SARM","DISC","-",
							"-","SARME","-","-","-",
							"SABME","SNRM","-","RSET","-",
							"-","-","XID","-","-",
							"-","SNRME","-","-","-","-"};
	unsigned char res[][8]={"UI","RIM","-","-","-",
							"-","-","-","RD","-",
							"-","-","UA","-","-",
							"-","-","FRMR","-","-",
							"-","-","-","XID","-",
							"-","-","-","-","-","-","-"};
	unsigned char e;
	unsigned char cr;
	int i;
	int j;
	for (i=0; i<20; i++){
		cr=t[i][15]&1;
		printf("\nTrama %d\n", i+1);
		printf(".::Cabecera Ethernet::.\n");
		printf("MAC destino:");	
		for (j=0;j<6;j++){
			printf(" %.2x ", t[i][j]);
		}
		printf("\n");
		printf("MAC origen:");
		for (j=6;j<12;j++){
			printf(" %.2x ", t[i][j]);
		}
		printf("\n");
		unsigned short tt=(t[i][12]<<8)|t[i][13];
		
		if(tt<1500){
			printf("Tam: %d bytes \n", tt);
			printf(".::Cabecera LLC::.\n");
			unsigned char tipt=t[i][16]&3;
			if(t[i][17]>1){
				e=1;
			}
			else{
				e=0;
			}

			switch(tipt){
				case 1:
					printf("Trama  de supervision\n");
					unsigned char cs=(t[i][16]>>2)&3;
					if(!e){
						printf("Comando: %s\n", ts[cs]);
						printf("N(r)=%d\n",t[i][16]>>5);	
					}
					else{
						printf("Comando: %s\n", ts[cs]);
						printf("N(r)=%d\n",t[i][17]>>1);		
					}
				break;
				case 3:
					printf("Trama no numerada\n");
					unsigned char m1=(t[i][16]&12)>>2;
					unsigned char m2=(t[i][16]&224)>>3;
					unsigned char m=m1|m2;
					if(!cr){
						printf("Comando: %s\n", com[m]);
					}
					else{
						printf("Comando: %s\n", res[m]);
					}
				break;
				default:
					printf("Trama de informacion\n");
					if(!e){
						printf("N(s)=%d N(r)=%d\n", ((t[i][16]>>1)&7), ((t[i][16]>>5)&7));
					}	
					else{
						printf("N(s)=%d N(r)=%d\n", ((t[i][16]>>1)&63), ((t[i][17]>>1)&63));
					}
					
				break;
			}
		}
		else{
			if(tt==2054){
				unsigned char tamhw=t[i][18];
				unsigned char tamprot=t[i][19];
				printf(".::Cabecera ARP::.\n");	
				printf("Tipo de direccion de Hardware: ");
				if (t[i][15]==1){
					printf("Ethernet\n");
				}
				else{
					printf("IEEE 802 LAN\n");
				}
				printf("Tipo de direccion de protocolo: ");
				if(t[i][16]==8){
		            printf("2048 IPv4\n");
		        }

		        printf("Tamaño de la Dirección de Hardware: %d\n", tamhw);
		        printf("Tamaño de la Dirección de Protocolo: %d\n", tamprot);
		        if(t[i][21]==1){
		        	printf("Codigo de operacion: Solicitud\n");
		        }
		        else{
		        	printf("Codigo de operacion: Respuesta\n");
		        }
		        printf("MAC origen: ");
		        for (j=22; j<(22+tamhw); j++){
		        	printf(" %.2x ", t[i][j+6]);
		        }
		        printf("\n");
		        printf("IP origen: ");
		        for (j=22+(tamhw); j<(22+tamhw+tamprot); j++){
		        	printf(" %d ", t[i][j]);
		        }
		        printf("\n");
		        printf("MAC destino: ");
		        for (j=(22+tamhw+tamprot); j<(22+(2*tamhw)+tamprot); j++){
		        	printf(" %.2x ", t[i][j]);
		        }
		        printf("\n");
		        printf("IP destino: ");
		        for (j=(22+(2*tamhw)+tamprot); j<(22+(2*tamhw)+(2*tamprot)); j++){
		        	printf(" %d ", t[i][j]);
		        }
		        printf("\n");
			}	
			else if(tt==2048){
				unsigned char ihl=(t[i][14]&15)*4;
				printf(".::Cabecera IP::.\n");
				printf("Version: %d\n", t[i][14]>>4);
				printf("IHL %d\n", ihl);
	         	printf("Tipo de Servicio: \n");
			  	printf("D: %d\n", t[i][15]&16);
    		  	printf("T: %d\n", t[i][15]&8);
	          	printf("R: %d\n", t[i][15]&4);
	          	printf("C: %d\n", t[i][15]&2);
	          	printf("X: %d\n", t[i][15]&1);
	          	printf("Tam Total: %d\n", t[i][16]*256+t[i][17]);
	          	printf("ID: %.2x %.2x \n", t[i][18], t[i][19]);
	          	printf("Banderas: \n");
	          	printf("X: %d\n", t[i][20]>>7);
          		printf("D: %d\n",(t[i][20]>>6)&1);
	          	printf("M: %d\n",(t[i][20]>>5)&1);
	          	printf("Fragment Offset: %d\n", (t[i][20]&31)*256+t[i][21]);
	          	printf("Tiempo de vida: %d saltos\n", t[i][22]);
	          	printf("Protocolo: ");
	          	switch(t[i][23]){
	          		case 1:
	          			printf("ICMP\n");
	          		break;
	          		case 2:
	          			printf("IGMP\n");
	          		break;
	          		case 6:
	          			printf("TCP\n");
	          		break;
	          		case 9:
	          			printf("IGRP\n");
	          		break;
	          		case 17:
	          			printf("UDP\n");
	          		break;
	          		case 47:
	          			printf("GRE\n");
	          		break;
	          		case 50:
	          			printf("ESP\n");
	          		break;
	          		case 51:
	          			printf("AH\n");
	          		break;
	          		case 57:
	          			printf("SKIP\n");
	          		break;
	          		case 88:
	          			printf("EIGRP\n");
	          		break;
	          		case 89:
	          			printf("OSPF\n");
	          		break;
	          		case 115:
	          			printf("L2TP\n");
	          		break;
	          	}
		        printf("Checksum: %.2x %.2x \n", t[i][24], t[i][25]);
		        printf("IP Origen: ");
	          	for(j=26; j<30; j++){
              		printf(" %d ", t[i][j]);
	          	}
	          	printf("\n");
          		printf("IP Destino: ");
	          	for(j=30; j<34; j++){
              		printf(" %d ", t[i][j]);            
	          	}
	          	printf("\n");
	          	unsigned char prot=ihl+14;
	          	if(prot>34){
					printf("Opciones: \n");
					for (j=34; j<(ihl+14); j++){
						switch(t[i][j]){
							case 0:
								printf("End of option list \n");
								j=ihl+14;
							break;
							case 1:
								printf("No operation (pad)\n");
							break;
							case 7:
								printf("Record route\n");
							break;
							case 68:
								printf("Timestamp\n");
							break;
							case 131:
								printf("Loose source route\n");
							break;
							case 137:
								printf("Strict source route\n");
							break;
						}
					}
				}
				switch(t[i][23]){
					case 1:
						printf(".::Protocolo ICMP::.\n");
						printf("Tipo: ");
						switch(t[i][prot]){
							case 0:
								printf("Echo reply\n");
							break;
							case 3:
								printf("Destination unreachable\n");
							break;
							case 4:
								printf("Source quench\n");
							break;
							case 5:
								printf("Redirect\n");
							break;
							case 8:
								printf("Echo\n");
							break;
							case 9:
								printf("Router advertisement\n");
							break;
							case 10:
								printf("Router selection\n");
							break;
							case 11:
								printf("Time exceeded\n");
							break;
							case 12:
								printf("Parameter problem\n");
							break;
							case 13:
								printf("Timestamp\n");
							break;
							case 14:
								printf("Timestamp reply\n");
							break;
							case 15:
								printf("Information request\n");
							break;
							case 16:
								printf("Inforation reply\n");
							break;
							case 17:
								printf("Address mark request\n");
							break;
							case 18:
								printf("Address mark reply\n");
							break;
							case 30:
								printf("Traceroute\n");
							break;
						}
						printf("Code: %d\n", t[i][prot+1]);
						printf("Checksum: %.2x %.2x \n", t[i][prot+2], t[i][prot+3]);
					break;
					case 6:
						printf(".::Protocolo TCP::.\n");
						printf("Puerto origen: ");
						switch((t[i][prot]*256)+t[i][prot+1]){
							case 7:
								printf("Echo\n");
							break;
							case 19:
								printf("Chargen\n");
							break;
							case 20:
								printf("FTP-data\n");
							break;
							case 21:
								printf("FTP-control\n");
							break;
							case 22:
								printf("SSH\n");
							break;
							case 23:
								printf("Telnet\n");	
							break;
							case 25:
								printf("SMTP\n");
							break;
							case 53:
								printf("Domain\n");
							break;
							case 79:
								printf("Finger\n");
							break;
							case 80:
								printf("HTTP\n");
							break;
							case 110:
								printf("POP3\n");
							break;
							case 111:
								printf("Sunrpc\n");
							break;
							case 119:
								printf("NNTP\n");
							break;
							case 139:
								printf("Netbios-SSN\n");
							break;
							case 143:
								printf("IMAP\n");
							break;
							case 179:
								printf("BGP\n");
							break;
							case 389:
								printf("LDAP\n");
							break;
							case 443:
								printf("HTTPS (SSL)\n");
							break;
							case 445:
								printf("Microsoft-DS\n");
							break;
							case 1080:
								printf("Socks\n");
							break;
							default:
								printf("-\n");
							break;
						}
						printf("Puerto destino: ");
						switch((t[i][prot+2]*256)+t[i][prot+3]){
							case 7:
								printf("Echo\n");
							break;
							case 19:
								printf("Chargen\n");
							break;
							case 20:
								printf("FTP-data\n");
							break;
							case 21:
								printf("FTP-control\n");
							break;
							case 22:
								printf("SSH\n");
							break;
							case 23:
								printf("Telnet\n");	
							break;
							case 25:
								printf("SMTP\n");
							break;
							case 53:
								printf("Domain\n");
							break;
							case 79:
								printf("Finger\n");
							break;
							case 80:
								printf("HTTP\n");
							break;
							case 110:
								printf("POP3\n");
							break;
							case 111:
								printf("Sunrpc\n");
							break;
							case 119:
								printf("NNTP\n");
							break;
							case 139:
								printf("Netbios-SSN\n");
							break;
							case 143:
								printf("IMAP\n");
							break;
							case 179:
								printf("BGP\n");
							break;
							case 389:
								printf("LDAP\n");
							break;
							case 443:
								printf("HTTPS (SSL)\n");
							break;
							case 445:
								printf("Microsoft-DS\n");
							break;
							case 1080:
								printf("Socks\n");
							break;
							default:
								printf("-\n");
							break;
						}
						printf("Numero de secuencia: ");
						printf("%d\n", (t[i][prot+4]<<24)+(t[i][prot+5]<<16)+(t[i][prot+6]<<8)+ t[i][prot+7]);
						printf("Numero de ACK: ");
						printf("%d\n", (t[i][prot+8]<<24)+(t[i][prot+9]<<16)+(t[i][prot+10]<<8)+t[i][prot+11]);
						unsigned char headerlength=(t[i][prot+12]>>4)*4;
						printf("Offset: ");
						printf("%d\n", headerlength);
						printf("Flags:\n U: %d \n A: %d\n P: %d\n R: %d\n S: %d\n F: %d\n", 
							(t[i][prot+13]>>5)&1, (t[i][prot+13]>>4)&1, 
							(t[i][prot+13]>>3)&1, (t[i][prot+13]>>2)&1, 
							(t[i][prot+13]>>1)&1, t[i][prot+13]&1);
						printf("Window: %d \n", t[i][prot+14]*256 +t[i][prot+15]);
						printf("Checksum: %.2X %.2X\n", t[i][prot+16], t[i][prot+17]);
						printf("Urgent Pointer %d \n", t[i][prot+18]*256+t[i][prot+19]);
						if((prot+20)<(prot+headerlength)){
							printf("Options: \n");
							for (j=(prot+20); j<(prot+headerlength); j++){
								switch(t[i][j]){
									case 0:
										printf("End of option list \n");
										j=prot+headerlength;
									break;
									case 1:
										printf("No operation (pad)\n");
									break;
									case 2:
										printf("Maximum segment size\n");
									break;
									case 3:
										printf("Window scale\n");
									break;
									case 4:
										printf("Selective ACK ok\n");
									break;
									case 8:
										printf("Timestamp\n");
									break;
									default:
										printf("-\n");
									break;
								}
							}
						}
					break;
					case 17:
						printf(".::Protocolo UDP::.\n");
						printf("Puerto origen: ");
						switch((t[i][prot]*256)+t[i][prot+1]){
							case 7:
								printf("Echo\n");
							break;
							case 19:
								printf("Chargen\n");
							break;
							case 37:
								printf("Time\n");
							break;
							break;
							case 53:
								printf("Domain\n");
							break;
							case 67:
								printf("Bootps (DHCP)\n");
							break;
							case 68:
								printf("Bootpc (DHCP)\n");
							break;
							case 69:
								printf("TFTP\n");
							break;
							case 137:
								printf("Netbios-NS\n");
							break;
							case 138:
								printf("Netbios-DGM\n");
							break;
							case 161:
								printf("SNMP\n");
							break;
							case 162:
								printf("SNMP-TRAP\n");
							break;
							case 500:
								printf("ISAKMP\n");
							break;
							case 514:
								printf("SYSLOG\n");
							break;
							case 520:
								printf("RIP\n");
							break;
							case 33434:
								printf("Traceroute\n");
							break;
							default:
								printf("-\n");
							break;
						}
						printf("Puerto destino: ");
						switch((t[i][prot+2]*256)+t[i][prot+3]){
							case 7:
								printf("Echo\n");
							break;
							case 19:
								printf("Chargen\n");
							break;
							case 37:
								printf("Time\n");
							break;
							break;
							case 53:
								printf("Domain\n");
							break;
							case 67:
								printf("Bootps (DHCP)\n");
							break;
							case 68:
								printf("Bootpc (DHCP)\n");
							break;
							case 69:
								printf("TFTP\n");
							break;
							case 137:
								printf("Netbios-NS\n");
							break;
							case 138:
								printf("Netbios-DGM\n");
							break;
							case 161:
								printf("SNMP\n");
							break;
							case 162:
								printf("SNMP-TRAP\n");
							break;
							case 500:
								printf("ISAKMP\n");
							break;
							case 514:
								printf("SYSLOG\n");
							break;
							case 520:
								printf("RIP\n");
							break;
							case 33434:
								printf("Traceroute\n");
							break;
							default:
								printf("-\n");
							break;
						}
						unsigned char length=t[i][prot+4]*256+t[i][prot+5];
						printf("Longitud: %d\n", length);
						printf("Checksum: %.2X %.2X\n", t[i][prot+6], t[i][prot+7]);
						for(j=prot+8; j<(prot+length); j++){
							printf("%c", t[i][j]);
						}
						printf("\n");
					break;
					default:
						printf("Ocurrio un error :(\n");
					break;
				}
			}
		}
		printf("---------------------------------------------------------------\n");
	}					   		
	return 0;
}

