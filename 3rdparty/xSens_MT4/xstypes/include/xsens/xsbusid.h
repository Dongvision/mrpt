/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          https://www.mrpt.org/                         |
   |                                                                        |
   | Copyright (c) 2005-2020, Individual contributors, see AUTHORS file     |
   | See: https://www.mrpt.org/Authors - All rights reserved.               |
   | Released under BSD License. See: https://www.mrpt.org/License          |
   +------------------------------------------------------------------------+ */
#ifndef XSBUSID_H
#define XSBUSID_H

/*! \addtogroup cinterface C Interface
	@{
*/

/*! \brief The bus identifier of the master device */
#define XS_BID_MASTER 0xFF

/*! \brief The bus broadcast bus identifier (all devices) */
#define XS_BID_BROADCAST 0x00

/*! \brief The bus identifier for the first MT on the bus */
#define XS_BID_MT 0x01

/*! \brief An invalid bus identifier */
#define XS_BID_INVALID 0xFE

/*! @} */

#endif  // file guard
