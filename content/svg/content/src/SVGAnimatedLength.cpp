/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "mozilla/dom/SVGAnimatedLength.h"
#include "mozilla/dom/SVGAnimatedLengthBinding.h"
#include "nsSVGLength2.h"

namespace mozilla {
namespace dom {

NS_SVG_VAL_IMPL_CYCLE_COLLECTION_WRAPPERCACHED(SVGAnimatedLength, mSVGElement)

NS_IMPL_CYCLE_COLLECTION_ROOT_NATIVE(SVGAnimatedLength, AddRef)
NS_IMPL_CYCLE_COLLECTION_UNROOT_NATIVE(SVGAnimatedLength, Release)

JSObject*
SVGAnimatedLength::WrapObject(JSContext* aCx)
{
  return SVGAnimatedLengthBinding::Wrap(aCx, this);
}

already_AddRefed<nsIDOMSVGLength>
SVGAnimatedLength::BaseVal()
{
  nsRefPtr<nsIDOMSVGLength> angle;
  mVal->ToDOMBaseVal(getter_AddRefs(angle), mSVGElement);
  return angle.forget();
}

already_AddRefed<nsIDOMSVGLength>
SVGAnimatedLength::AnimVal()
{
  nsRefPtr<nsIDOMSVGLength> angle;
  mVal->ToDOMAnimVal(getter_AddRefs(angle), mSVGElement);
  return angle.forget();
}

} // namespace dom
} // namespace mozilla
