package com.sang.database;

import java.io.Serializable;

public class IdDistributionCentre implements Serializable {
    private int uid = 0;
    private int sid = 0;
    public static final int uidNumLimit = 1000;
    public static final int sidNumLimit = 1000;
    private static final long serialVersionUID = 7249261246761182397L;
    public synchronized int getNextUid() throws UnFormatException {
        if(uid < uidNumLimit) return uid++;
        else throw new UnFormatException("register patient/doctor num exceed limit");
    }
    public synchronized int getNextSid() throws UnFormatException {
        if(sid < sidNumLimit) return sid++;
        else throw new UnFormatException("register sid num exceed limit");
    }

}
