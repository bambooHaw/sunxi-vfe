/* 
 ***************************************************************************************
 * 
 * cci_helper.h
 * 
 * Hawkview ISP - cci_helper.h module
 * 
 * Copyright (c) 2014 by Allwinnertech Co., Ltd.  http://www.allwinnertech.com
 * 
 * Version		  Author         Date		    Description
 * 
 *   2.0		  Yang Feng   	2014/06/06	      Second Version
 * 
 ****************************************************************************************
 */

#ifndef __VFE__I2C__H__
#define __VFE__I2C__H__

#include <linux/i2c.h>
#include <media/v4l2-subdev.h>
#include <media/v4l2-device.h>

struct cci_driver
{
	unsigned short id;
	char  name[32];
	struct device cci_device;
	struct device_attribute dev_attr_cci;
	unsigned short cci_id;
	unsigned short cci_saddr;
	struct v4l2_subdev *sd;
	unsigned int is_drv_registerd;
	unsigned int is_matched;
	
	int addr_width;
	int data_width;
	int read_flag;
	short read_value;
	struct mutex cci_mutex;
	//int (*probe)(struct i2c_client *, const struct i2c_device_id *);
	//int (*remove)(struct i2c_client *);
	struct list_head cci_list;
};

struct reg_list_a8_d8 {
  unsigned char addr;
  unsigned char data;
};

struct reg_list_a8_d16 {
  unsigned char addr;
  unsigned short data;
};

struct reg_list_a16_d8 {
  unsigned short addr;
  unsigned char data;
};

struct reg_list_a16_d16 {
  unsigned short addr;
  unsigned short data;
};

struct reg_list_w_a16_d16 {
  unsigned short width;
  unsigned short addr;
  unsigned short data;
};

typedef unsigned short addr_type;
typedef unsigned short data_type;

extern void csi_cci_init_helper(unsigned int sel);
extern void csi_cci_exit_helper(unsigned int sel);

extern int cci_read_a8_d8(struct v4l2_subdev *sd, unsigned char addr,unsigned char *value);
extern int cci_write_a8_d8(struct v4l2_subdev *sd, unsigned char addr,unsigned char value);
extern int cci_read_a8_d16(struct v4l2_subdev *sd, unsigned char addr,unsigned short *value);
extern int cci_write_a8_d16(struct v4l2_subdev *sd, unsigned char addr,unsigned short value);
extern int cci_read_a16_d8(struct v4l2_subdev *sd, unsigned short addr,unsigned char *value);
extern int cci_write_a16_d8(struct v4l2_subdev *sd, unsigned short addr,unsigned char value);
extern int cci_read_a16_d16(struct v4l2_subdev *sd, unsigned short addr,unsigned short *value);
extern int cci_write_a16_d16(struct v4l2_subdev *sd, unsigned short addr,unsigned short value);
extern int cci_write_a16_d32(struct v4l2_subdev *sd, unsigned short addr,unsigned int value);

extern int cci_read_a0_d16(struct v4l2_subdev *sd, unsigned short *value);
extern int cci_write_a0_d16(struct v4l2_subdev *sd, unsigned short value);
extern int cci_write_a16_d8_continuous_helper(struct v4l2_subdev *sd, unsigned short addr, unsigned char *vals , uint size);
extern int cci_read(struct v4l2_subdev *sd, addr_type addr, data_type *value);
extern int cci_write(struct v4l2_subdev *sd, addr_type addr, data_type value);

extern struct cci_driver *to_cci_drv(struct v4l2_subdev *sd);
extern void cci_subdev_init(struct v4l2_subdev *sd, struct cci_driver *drv_data, const struct v4l2_subdev_ops *ops);
extern struct v4l2_subdev *cci_bus_match(char* name, unsigned short cci_id, unsigned short cci_saddr);
extern void cci_bus_match_cancel(struct cci_driver *cci_drv_p);
extern void csi_cci_bus_unmatch_helper(unsigned int sel);

extern void cci_lock(struct v4l2_subdev *sd);
extern void cci_unlock(struct v4l2_subdev *sd);

extern int cci_dev_init_helper(struct i2c_driver *sensor_driver);
extern void cci_dev_exit_helper(struct i2c_driver *sensor_driver);
extern int cci_dev_probe_helper(struct v4l2_subdev *sd, struct i2c_client *client, const struct v4l2_subdev_ops *sensor_ops, struct cci_driver *cci_drv);
extern struct v4l2_subdev *cci_dev_remove_helper(struct i2c_client *client, struct cci_driver *cci_drv);


#endif //__VFE__I2C__H__
