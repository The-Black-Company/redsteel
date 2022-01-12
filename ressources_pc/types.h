// Jason Brillante "Damdoshi"
// Hanged Bunny Studio 2014-2021
// Pentacle Technologie 2008-2021
//
// RedSteel

#ifndef				__REDSTEEL_TYPES_H__
# define			__REDSTEEL_TYPES_H__
# include			<stdint.h>

# define			TOTAL_ADDRESS_SPACE			(1 << 16)
# define			NBR_SEGMENT				8
# define			SEGMENT_SIZE				(TOTAL_ADDRESS_SPACE / NBR_SEGMENT)

# define			MAX_REGISTER				31

typedef int16_t			byte;
typedef uint16_t		ubyte;
typedef uint8_t			bit;
typedef uint16_t		address;

# define			UBYTE_MAX				(TOTAL_ADDRESS_SPACE - 1)
# define			BYTE_MAX				((TOTAL_ADDRESS_SPACE << 1) >> 1)
# define			BYTE_MIN				(1 << 15)

# define			RSNULL					0
# define			RSMAX					UBYTE_MAX

#endif	//			__REDSTEEL_TYPES_H__
