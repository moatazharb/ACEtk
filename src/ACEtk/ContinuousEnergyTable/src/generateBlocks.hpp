void generateBlocks() {

  auto begin = this->data().XSS().begin();
  auto esz = begin + this->data().JXS(1) - 1;
  auto nu = begin + this->data().JXS(2) - 1;
  auto mtr = begin + this->data().JXS(3) - 1;
  auto lqr = begin + this->data().JXS(4) - 1;
  auto tyr = begin + this->data().JXS(5) - 1;
  auto lsig = begin + this->data().JXS(6) - 1;
  auto sig = begin + this->data().JXS(7) - 1;
  auto land = begin + this->data().JXS(8) - 1;
  auto ang = begin + this->data().JXS(9) - 1;
  auto ldlw = begin + this->data().JXS(10) - 1;
  auto dlw = begin + this->data().JXS(11) - 1;
  auto gpd = begin + this->data().JXS(12) - 1;
  auto mtrp = this->NTRP() > 0 ? begin + this->data().JXS(13) - 1 : begin;
  auto lsigp = this->NTRP() > 0 ? begin + this->data().JXS(14) - 1 : begin;
  auto sigp = this->NTRP() > 0 ? begin + this->data().JXS(15) - 1 : begin;
  auto landp = this->NTRP() > 0 ? begin + this->data().JXS(16) - 1 : begin;
  auto andp = this->NTRP() > 0 ? begin + this->data().JXS(17) - 1 : begin;
  auto ldlwp = this->NTRP() > 0 ? begin + this->data().JXS(18) - 1 : begin;
  auto dlwp = this->NTRP() > 0 ? begin + this->data().JXS(19) - 1 : begin;
  auto yp = this->NTRP() > 0 ? begin + this->data().JXS(20) - 1 : begin;

  auto ptype = begin + this->data().JXS(30) - 1;
  auto ntro = begin + this->data().JXS(31) - 1;

  this->esz_ = block::ESZ( esz, this->data().JXS(2) > 0 ? nu : mtr, this->NES() );
  this->nu_ = block::NU( this->data().JXS(2) > 0 ? nu : mtr, mtr );
  this->mtr_ = block::MTR( mtr, lqr, this->NTR() );
  this->lqr_ = block::LQR( lqr, tyr, this->NTR() );
  this->tyr_ = block::TYR( tyr, lsig, this->NTR() );
  this->sig_ = block::SIG( lsig, sig, land, this->NTR() );
  this->and_ = block::AND( land, ang, ldlw, this->NR() );
  this->dlw_ = block::DLW( ldlw, dlw, gpd, this->NR() );

  // secondary photon data
  this->gpd_ = block::GPD( gpd, mtrp, this->NES() );
  this->mtrp_ = block::MTR( mtrp, lsigp, this->NTRP() );
  this->sigp_ = block::SIGP( lsigp, sigp, landp, this->NTRP() );
  this->andp_ = block::ANDH( landp, andp, ldlwp, this->NTRP() );
  this->dlwp_ = block::DLW( ldlwp, dlwp, yp, this->NTRP() );
  this->yp_ = block::YP( yp, this->data().XSS().end() );

  // secondary particle data
  this->ptype_ = block::PTYPE( ptype, ntro, this->NTYPE() );
}
