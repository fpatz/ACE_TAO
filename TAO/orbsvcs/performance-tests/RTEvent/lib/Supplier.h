/**
 * @file Supplier.h
 *
 * $Id$
 *
 * @author Carlos O'Ryan <coryan@uci.edu>
 */

#ifndef TAO_PERF_RTEC_SUPPLIER_H
#define TAO_PERF_RTEC_SUPPLIER_H

#include "rtec_perf_export.h"
#include "orbsvcs/RtecEventCommS.h"
#include "orbsvcs/RtecEventChannelAdminC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class Supplier
 *
 * @brief Implement a simple supplier to keep track of the latency
 *
 */
class TAO_RTEC_Perf_Export Supplier
  : public virtual POA_RtecEventComm::PushSupplier
  , public virtual PortableServer::RefCountServantBase
{
public:
  /// Constructor
  /**
   * The experiment ID is used to configure the supplier ID on the
   * publication.
   */
  Supplier (CORBA::Long experiment_id,
            CORBA::Long event_type);

  /// Connect to the event channel
  void connect (RtecEventChannelAdmin::EventChannel_ptr ec
                ACE_ENV_ARG_DECL);

  /// Disconnect from the event channel
  void disconnect (ACE_ENV_SINGLE_ARG_DECL);

  void push (const RtecEventComm::EventSet &events
             ACE_ENV_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));

  //@{
  /** @name The RtecEventComm::PushSupplier methods
   */
  virtual void disconnect_push_supplier (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
    ACE_THROW_SPEC ((CORBA::SystemException));
  //@}

private:
  /// The experiment id
  /// Synchronize access to the internal data
  TAO_SYNCH_MUTEX mutex_;

  /// The experiment id
  CORBA::Long experiment_id_;

  /// The event type
  CORBA::Long event_type_;

  /// The proxy this object is connected to
  RtecEventChannelAdmin::ProxyPushConsumer_var proxy_consumer_;
};

#endif /* TAO_PERF_RTEC_SUPPLIER_H */
