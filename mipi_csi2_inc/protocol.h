#ifndef __PROTOCOL__H__
#define __PROTOCOL__H__

enum bit_order
{
  LSB_FST,
  MSB_FST,
};

enum byte_order
{
  WCh_WCl_DI,
  DI_WCh_WCl,
  WCl_WCh,DI,
  DI_WCl_WCh,
};

enum source_type
{
  PROGRESSIVE,
  INTERLACED,
};

enum line_sync
{
  TGL_PKT,
  TGL_LSLE,
};

enum pkt_fmt
{
  MIPI_FS           = 0X00, //short packet      
  MIPI_FE           = 0X01,
  MIPI_LS           = 0X02,
  MIPI_LE           = 0X03,
  MIPI_SDAT0          = 0X08,
  MIPI_SDAT1          = 0X09,
  MIPI_SDAT2          = 0X0A,
  MIPI_SDAT3          = 0X0B,
  MIPI_SDAT4          = 0X0C,
  MIPI_SDAT5          = 0X0D,
  MIPI_SDAT6          = 0X0E,
  MIPI_SDAT7          = 0X0F,             
//  NULL          = 0X10, //long packet      
  MIPI_BLK            = 0X11,
  MIPI_EMBD         = 0X12,
  MIPI_YUV420       = 0X18,
  MIPI_YUV420_10    = 0X19,
  MIPI_YUV420_CSP   = 0X1C,
  MIPI_YUV420_CSP_10 =  0X1D,
  MIPI_YUV422       = 0X1E,
  MIPI_YUV422_10    = 0X1F,
  MIPI_RGB565       = 0X22,
  MIPI_RGB888       = 0X24,
  MIPI_RAW8         = 0X2A,
  MIPI_RAW10          = 0X2B,
  MIPI_RAW12          = 0X2C,
  MIPI_USR_DAT0     = 0X30,
  MIPI_USR_DAT1     = 0X31,
  MIPI_USR_DAT2     = 0X32,
  MIPI_USR_DAT3     = 0X33,
  MIPI_USR_DAT4     = 0X34,
  MIPI_USR_DAT5     = 0X35,
  MIPI_USR_DAT6     = 0X36,
  MIPI_USR_DAT7     = 0X37,
};

enum protocol_int
{
  FIFO_OVER_INT         ,
  FRAME_END_SYNC_INT    ,
  FRAME_START_SYNC_INT  ,
  LINE_END_SYNC_INT     ,
  LINE_START_SYNC_INT   ,
  PH_UPDATE_INT         ,
  PF_INT                ,
  EMB_DATA_INT          ,
  FRAME_SYNC_ERR_INT    ,
  LINE_SYNC_ERR_INT     ,
  ECC_ERR_INT           ,
  ECC_WRN_INT           ,
  CHKSUM_ERR_INT        ,
  EOT_ERR_INT           ,
};

#endif
