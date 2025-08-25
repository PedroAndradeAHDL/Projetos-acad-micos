package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

import java.util.Calendar;
import java.util.Random;

public class Xogum extends Edo_Society implements SupremeGovernance {
	
	private String family;
	
	private Calendar reignStart;
	private Calendar reignEnd;
	
	private static Xogum xogum = new Xogum(); //objeto unico
	
	private Xogum() {
	}

	@Override
	public boolean politicalAction(String action) {
		Random decision = new Random(); 
		int finalDecision = decision.nextInt(100); 
		if(finalDecision < 42) 
			{
			return true; 
			} else return false;

	}

	public String getFamily() {
		return family;
	}

	public void setFamily(String family) {
		this.family = family;
	}

	public Calendar getReignStart() {
		return reignStart;
	}

	public void setReignStart(Calendar reignStart) {
		this.reignStart = reignStart;
	}

	public Calendar getReignEnd() {
		return reignEnd;
	}

	public void setReignEnd(Calendar reignEnd) {
		this.reignEnd = reignEnd;
	}

	public static Xogum getXogum() {
		return xogum;
	}


}
