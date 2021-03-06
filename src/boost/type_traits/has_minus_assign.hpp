//  (C) Copyright 2009-2011 Frederic Bron.
//
//  Use, modification and distribution are subject to the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt).
//
//  See http://www.boost.org/libs/type_traits for most recent version including documentation.

#ifndef BOOST_TT_HAS_MINUS_ASSIGN_HPP_INCLUDED
#define BOOST_TT_HAS_MINUS_ASSIGN_HPP_INCLUDED

#define BOOST_TT_TRAIT_NAME has_minus_assign
#define BOOST_TT_TRAIT_OP -=
#define BOOST_TT_FORBIDDEN_IF\
   (\
      /* Lhs==pointer and Rhs==fundamental and Rhs!=integral */\
      (\
         ::network_boost::is_pointer< Lhs_noref >::value && \
         ::network_boost::is_fundamental< Rhs_nocv >::value && \
         (!  ::network_boost::is_integral< Rhs_noref >::value )\
      ) || \
      /* Lhs==void* and Rhs==fundamental */\
      (\
         ::network_boost::is_pointer< Lhs_noref >::value && \
         ::network_boost::is_void< Lhs_noptr >::value && \
         ::network_boost::is_fundamental< Rhs_nocv >::value\
      ) || \
      /* Rhs==void* and Lhs==fundamental */\
      (\
         ::network_boost::is_pointer< Rhs_noref >::value && \
         ::network_boost::is_void< Rhs_noptr >::value && \
         ::network_boost::is_fundamental< Lhs_nocv >::value\
      ) || \
      /* Lhs=fundamental and Rhs=pointer */\
      (\
         ::network_boost::is_fundamental< Lhs_nocv >::value && \
         ::network_boost::is_pointer< Rhs_noref >::value\
      ) || \
      /* Lhs==pointer and Rhs==pointer */\
      (\
         ::network_boost::is_pointer< Lhs_noref >::value && \
         ::network_boost::is_pointer< Rhs_noref >::value\
      ) || \
      /* (Lhs==fundamental or Lhs==pointer) and (Rhs==fundamental or Rhs==pointer) and (Lhs==const) */\
      (\
         (\
            ::network_boost::is_fundamental< Lhs_nocv >::value || \
            ::network_boost::is_pointer< Lhs_noref >::value\
         ) && \
         (\
            ::network_boost::is_fundamental< Rhs_nocv >::value || \
            ::network_boost::is_pointer< Rhs_noref >::value\
          ) && \
         ::network_boost::is_const< Lhs_noref >::value\
      )\
      )


#include <boost/type_traits/detail/has_binary_operator.hpp>

#undef BOOST_TT_TRAIT_NAME
#undef BOOST_TT_TRAIT_OP
#undef BOOST_TT_FORBIDDEN_IF

#endif
