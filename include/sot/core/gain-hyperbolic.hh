/*
 * Copyright 2010,
 * François Bleibel,
 * Olivier Stasse,
 *
 * CNRS/AIST
 *
 * This file is part of sot-core.
 * sot-core is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 * sot-core is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.  You should
 * have received a copy of the GNU Lesser General Public License along
 * with sot-core.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SOT_GAIN_HYPERBOLIC_HH__
#define __SOT_GAIN_HYPERBOLIC_HH__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* Matrix */
#include <dynamic-graph/linear-algebra.h>
namespace dg = dynamicgraph;

/* SOT */
#include <dynamic-graph/all-signals.h>
#include <dynamic-graph/all-signals.h>
#include <dynamic-graph/entity.h>

/* --------------------------------------------------------------------- */
/* --- API ------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

#if defined (WIN32)
#  if defined (gain_hyperbolic_EXPORTS)
#    define SOTGAINHYPERBOLIC_EXPORT __declspec(dllexport)
#  else
#    define SOTGAINHYPERBOLIC_EXPORT  __declspec(dllimport)
#  endif
#else
#  define SOTGAINHYPERBOLIC_EXPORT
#endif

/* --------------------------------------------------------------------- */
/* --- CLASS ----------------------------------------------------------- */
/* --------------------------------------------------------------------- */

namespace dynamicgraph { namespace sot {
namespace dg = dynamicgraph;

class SOTGAINHYPERBOLIC_EXPORT GainHyperbolic
: public dg::Entity
{

 public: /* --- CONSTANTS --- */

  /* Default values. */
  static const double ZERO_DEFAULT;   // = 0.1
  static const double INFTY_DEFAULT;  // = 0.1
  static const double TAN_DEFAULT;    // = 1.

 public: /* --- ENTITY INHERITANCE --- */
  static const std::string CLASS_NAME;
  virtual void display( std::ostream& os ) const;
  virtual const std::string& getClassName( void ) const { return CLASS_NAME; }


 protected:

  /* Parameters of the hyperbolic-gain function:
   * lambda (x) = a * exp (-b*x) + c. */
  double coeff_a;
  double coeff_b;
  double coeff_c;
  double coeff_d;

 public: /* --- CONSTRUCTORS ---- */

  GainHyperbolic( const std::string & name );
  GainHyperbolic( const std::string & name,const double& lambda );
  GainHyperbolic( const std::string & name,
		     const double& valueAt0,
		     const double& valueAtInfty,
		     const double& tanAt0,
		     const double& decal0 );

 public: /* --- INIT --- */

  inline void init( void ) { init( ZERO_DEFAULT,INFTY_DEFAULT,TAN_DEFAULT,0 ); }
  inline void init( const double& lambda ) { init( lambda,lambda,1.,0); }
  void init( const double& valueAt0,
	     const double& valueAtInfty,
	     const double& tanAt0,
	     const double& decal0 );
  void forceConstant( void );

 public:  /* --- SIGNALS --- */
  dg::SignalPtr<dg::Vector,int> errorSIN;
  dg::SignalTimeDependent<double,int> gainSOUT;
 protected:
  double& computeGain( double& res,int t );

 public: /* --- PARAMS --- */
  virtual void commandLine( const std::string& cmdLine,std::istringstream& cmdArgs,
			    std::ostream& os );
};

} /* namespace sot */} /* namespace dynamicgraph */



#endif // #ifndef __SOT_GAIN_HYPERBOLIC_HH__
