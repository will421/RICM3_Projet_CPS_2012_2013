
typedef struct _image_datas image_data;

enum typeImage {
	P1=1,
	P2=2,
	P3=3
};

struct _image_datas {
	enum typeImage t;
	uint32_t l;
	uint32_t h;
	int vmax;
	uint64_t * data;
};

